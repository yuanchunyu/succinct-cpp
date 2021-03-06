#ifndef SUCCINCT_KV_BENCHMARK_H_
#define SUCCINCT_KV_BENCHMARK_H_

#include "benchmark.h"
#include "succinctkv_client.h"
#include "succinct_shard.h"

class SuccinctKVBenchmark : public Benchmark {
 public:

  SuccinctKVBenchmark(std::string query_file = "")
      : Benchmark() {
    fprintf(stderr, "Connecting to server...\n");

    try {
      client_ = new SuccinctKVClient("localhost");
    } catch (std::exception& e) {
      fprintf(stderr, "Could not create SuccinctKVClient:%s\n", e.what());
    }
    fprintf(stderr, "Connected!\n");

    GenerateRandoms();
    if (query_file != "") {
      ReadQueries(query_file);
    }
  }

  ~SuccinctKVBenchmark() {
    delete client_;
  }

  void BenchmarkGetLatency(std::string result_path) {

    TimeStamp t0, t1, tdiff;
    uint64_t sum;
    std::ofstream result_stream(result_path);

    // Warmup
    sum = 0;
    fprintf(stderr, "Warming up for %llu queries...\n", kWarmupCount);
    for (uint64_t i = 0; i < kWarmupCount; i++) {
      std::string result;
      client_->Get(result, randoms_[i]);
      sum = (sum + result.length()) % kMaxSum;
    }
    fprintf(stderr, "Warmup chksum = %llu\n", sum);
    fprintf(stderr, "Warmup complete.\n");

    // Measure
    sum = 0;
    fprintf(stderr, "Measuring for %llu queries...\n", kMeasureCount);
    for (uint64_t i = kWarmupCount; i < kWarmupCount + kMeasureCount; i++) {
      std::string result;
      t0 = GetTimestamp();
      client_->Get(result, randoms_[i]);
      t1 = GetTimestamp();
      tdiff = t1 - t0;
      result_stream << randoms_[i] << "\t" << tdiff << "\n";
      sum = (sum + result.length()) % kMaxSum;
    }
    fprintf(stderr, "Measure chksum = %llu\n", sum);
    fprintf(stderr, "Measure complete.\n");

    result_stream.close();

  }

  void BenchmarkAccessLatency(std::string result_path, int32_t fetch_length) {

    TimeStamp t0, t1, tdiff;
    uint64_t sum;
    std::ofstream result_stream(result_path);

    // Warmup
    sum = 0;
    fprintf(stderr, "Warming up for %llu queries...\n", kWarmupCount);
    for (uint64_t i = 0; i < kWarmupCount; i++) {
      std::string result;
      client_->Access(result, randoms_[i], 0, fetch_length);
      sum = (sum + result.length()) % kMaxSum;
    }
    fprintf(stderr, "Warmup chksum = %llu\n", sum);
    fprintf(stderr, "Warmup complete.\n");

    // Measure
    sum = 0;
    fprintf(stderr, "Measuring for %llu queries...\n", kMeasureCount);
    for (uint64_t i = kWarmupCount; i < kWarmupCount + kMeasureCount; i++) {
      std::string result;
      t0 = GetTimestamp();
      client_->Access(result, randoms_[i], 0, fetch_length);
      t1 = GetTimestamp();
      tdiff = t1 - t0;
      result_stream << randoms_[i] << "\t" << tdiff << "\n";
      sum = (sum + result.length()) % kMaxSum;
    }
    fprintf(stderr, "Measure chksum = %llu\n", sum);
    fprintf(stderr, "Measure complete.\n");

    result_stream.close();

  }

  void BenchmarkCountLatency(std::string result_path) {

    TimeStamp t0, t1, tdiff;
    uint64_t sum;
    std::ofstream result_stream(result_path);

    // Warmup
    sum = 0;
    fprintf(stderr, "Warming up for %llu queries...\n", kWarmupCount);
    for (uint64_t i = 0; i < std::min(queries_.size(), 100UL); i++) {
      uint64_t result;
      result = client_->Count(queries_[i]);
      sum = (sum + result) % kMaxSum;
    }
    fprintf(stderr, "Warmup chksum = %llu\n", sum);
    fprintf(stderr, "Warmup complete.\n");

    // Measure
    sum = 0;
    fprintf(stderr, "Measuring for %llu queries...\n", kMeasureCount);
    for (uint64_t i = 0; i < queries_.size(); i++) {
      uint64_t result;
      t0 = GetTimestamp();
      result = client_->Count(queries_[i]);
      t1 = GetTimestamp();
      tdiff = t1 - t0;
      result_stream << queries_[i] << "\t" << tdiff << "\n";
      sum = (sum + result) % kMaxSum;
    }
    fprintf(stderr, "Measure chksum = %llu\n", sum);
    fprintf(stderr, "Measure complete.\n");

    result_stream.close();

  }

  void BenchmarkSearchLatency(std::string result_path) {
    TimeStamp t0, t1, tdiff;
    uint64_t sum;
    std::ofstream result_stream(result_path);

    // Warmup
    sum = 0;
    fprintf(stderr, "Warming up for %zu queries...\n",
            std::min(queries_.size(), 100UL));
    for (uint64_t i = 0; i < std::min(queries_.size(), 100UL); i++) {
      std::set<int64_t> result;
      client_->Search(result, queries_[i]);
      sum = (sum + result.size()) % kMaxSum;
    }
    fprintf(stderr, "Warmup chksum = %llu\n", sum);
    fprintf(stderr, "Warmup complete.\n");

    // Measure
    sum = 0;
    fprintf(stderr, "Measuring for %zu queries...\n", queries_.size());
    for (uint64_t i = 0; i < queries_.size(); i++) {
      std::set<int64_t> result;
      t0 = GetTimestamp();
      client_->Search(result, queries_[i]);
      t1 = GetTimestamp();
      tdiff = t1 - t0;
      result_stream << result.size() << "\t" << tdiff << "\n";
      sum = (sum + result.size()) % kMaxSum;
    }
    fprintf(stderr, "Measure chksum = %llu\n", sum);
    fprintf(stderr, "Measure complete.\n");

    result_stream.close();
  }

  void BenchmarkRegexLatency(std::string result_path) {
    TimeStamp t0, t1, tdiff;
    uint64_t sum;
    std::ofstream result_stream(result_path);

    // Measure
    sum = 0;
    fprintf(stderr, "Measuring for %llu queries...\n", kMeasureCount);
    for (uint32_t i = 0; i < queries_.size(); i++) {
      for (uint32_t j = 0; j < 10; j++) {
        fprintf(stderr, "Running iteration %u of query %u\n", j, i);
        std::set<int64_t> result;
        t0 = GetTimestamp();
        client_->Regex(result, queries_[i]);
        t1 = GetTimestamp();
        tdiff = t1 - t0;
        result_stream << i << "\t" << j << "\t" << result.size() << "\t"
                      << tdiff << "\n";
        result_stream.flush();
        sum = (sum + result.size()) % kMaxSum;
      }
    }
    fprintf(stderr, "Measure chksum = %llu\n", sum);
    fprintf(stderr, "Measure complete.\n");

    result_stream.close();
  }

  static void *GetThroughput(void *ptr) {
    BenchmarkData data = *((BenchmarkData*) ptr);
    std::cout << "GET\n";

    SuccinctKVClient client = *(data.client);
    std::string value;

    double thput = 0;
    try {
      // Warmup phase
      long i = 0;
      TimeStamp warmup_start = GetTimestamp();
      while (GetTimestamp() - warmup_start < kWarmupTime) {
        client.Get(value, data.randoms[i % data.randoms.size()]);
        i++;
      }

      // Measure phase
      i = 0;
      TimeStamp start = GetTimestamp();
      while (GetTimestamp() - start < kMeasureTime) {
        client.Get(value, data.randoms[i % data.randoms.size()]);
        i++;
      }
      TimeStamp end = GetTimestamp();
      double totsecs = (double) (end - start) / (1000.0 * 1000.0);
      thput = ((double) i / totsecs);

      // Cooldown phase
      i = 0;
      TimeStamp cooldown_start = GetTimestamp();
      while (GetTimestamp() - cooldown_start < kCooldownTime) {
        client.Get(value, data.randoms[i % data.randoms.size()]);
        i++;
      }

    } catch (std::exception &e) {
      fprintf(stderr, "Throughput test ends...\n");
    }

    printf("Get throughput: %lf\n", thput);

    std::ofstream ofs;
    ofs.open("throughput_results_get", std::ofstream::out | std::ofstream::app);
    ofs << thput << "\n";
    ofs.close();

    return 0;
  }

  int BenchmarkGetThroughput(uint32_t num_threads) {
    pthread_t thread[num_threads];
    std::vector<BenchmarkData> data;
    fprintf(stderr, "Starting all threads...\n");
    for (uint32_t i = 0; i < num_threads; i++) {
      try {
        BenchmarkData th_data;
        th_data.client = new SuccinctKVClient("localhost");
        th_data.randoms = randoms_;
        data.push_back(th_data);
      } catch (std::exception& e) {
        fprintf(stderr, "Could not connect to handler on localhost : %s\n",
                e.what());
        return -1;
      }
    }
    fprintf(stderr, "Started %zu clients.\n", data.size());

    for (uint32_t current_t = 0; current_t < num_threads; current_t++) {
      int result = 0;
      result = pthread_create(&thread[current_t], NULL,
                              SuccinctKVBenchmark::GetThroughput,
                              static_cast<void*>(&(data[current_t])));
      if (result != 0) {
        fprintf(stderr, "Error creating thread %d; return code = %d\n",
                current_t, result);
      }
    }

    for (uint32_t current_t = 0; current_t < num_threads; current_t++) {
      pthread_join(thread[current_t], NULL);
    }
    fprintf(stderr, "All threads completed.\n");

    data.clear();
    return 0;
  }

  static void *AccessThroughput(void *ptr) {
    BenchmarkData data = *((BenchmarkData*) ptr);
    std::cout << "ACCESS\n";

    SuccinctKVClient client = *(data.client);
    std::string value;

    double thput = 0;
    try {
      // Warmup phase
      long i = 0;
      TimeStamp warmup_start = GetTimestamp();
      while (GetTimestamp() - warmup_start < kWarmupTime) {
        client.Access(value, data.randoms[i % data.randoms.size()], 0,
                      data.fetch_length);
        i++;
      }

      // Measure phase
      i = 0;
      TimeStamp start = GetTimestamp();
      while (GetTimestamp() - start < kMeasureTime) {
        client.Access(value, data.randoms[i % data.randoms.size()], 0,
                      data.fetch_length);
        i++;
      }
      TimeStamp end = GetTimestamp();
      double totsecs = (double) (end - start) / (1000.0 * 1000.0);
      thput = ((double) i / totsecs);

      // Cooldown phase
      i = 0;
      TimeStamp cooldown_start = GetTimestamp();
      while (GetTimestamp() - cooldown_start < kCooldownTime) {
        client.Access(value, data.randoms[i % data.randoms.size()], 0,
                      data.fetch_length);
        i++;
      }

    } catch (std::exception &e) {
      fprintf(stderr, "Throughput test ends...\n");
    }

    printf("Get throughput: %lf\n", thput);

    std::ofstream ofs;
    ofs.open("throughput_results_access",
             std::ofstream::out | std::ofstream::app);
    ofs << thput << "\n";
    ofs.close();

    return 0;
  }

  int BenchmarkAccessThroughput(uint32_t num_threads, int32_t len) {
    pthread_t thread[num_threads];
    std::vector<BenchmarkData> data;
    fprintf(stderr, "Starting all threads...\n");
    for (uint32_t i = 0; i < num_threads; i++) {
      try {
        BenchmarkData th_data;
        th_data.client = new SuccinctKVClient("localhost");
        th_data.randoms = randoms_;
        th_data.fetch_length = len;
        data.push_back(th_data);
      } catch (std::exception& e) {
        fprintf(stderr, "Could not connect to handler on localhost : %s\n",
                e.what());
        return -1;
      }
    }
    fprintf(stderr, "Started %zu clients.\n", data.size());

    for (uint32_t current_t = 0; current_t < num_threads; current_t++) {
      int result = 0;
      result = pthread_create(&thread[current_t], NULL,
                              SuccinctKVBenchmark::AccessThroughput,
                              static_cast<void*>(&(data[current_t])));
      if (result != 0) {
        fprintf(stderr, "Error creating thread %d; return code = %d\n",
                current_t, result);
      }
    }

    for (uint32_t current_t = 0; current_t < num_threads; current_t++) {
      pthread_join(thread[current_t], NULL);
    }
    fprintf(stderr, "All threads completed.\n");

    data.clear();
    return 0;
  }

  static void *SearchThroughput(void *ptr) {
    BenchmarkData data = *((BenchmarkData*) ptr);
    std::cout << "SEARCH\n";

    SuccinctKVClient client = *(data.client);

    double thput = 0;
    try {
      // Warmup phase
      long i = 0;
      TimeStamp warmup_start = GetTimestamp();
      while (GetTimestamp() - warmup_start < kWarmupTime) {
        std::set<int64_t> results;
        client.Search(results, data.queries[i % data.queries.size()]);
        i++;
      }

      // Measure phase
      i = 0;
      TimeStamp start = GetTimestamp();
      while (GetTimestamp() - start < kMeasureTime) {
        std::set<int64_t> results;
        client.Search(results, data.queries[i % data.queries.size()]);
        i++;
      }
      TimeStamp end = GetTimestamp();
      double totsecs = (double) (end - start) / (1000.0 * 1000.0);
      thput = ((double) i / totsecs);

      // Cooldown phase
      i = 0;
      TimeStamp cooldown_start = GetTimestamp();
      while (GetTimestamp() - cooldown_start < kCooldownTime) {
        std::set<int64_t> results;
        client.Search(results, data.queries[i % data.queries.size()]);
        i++;
      }

    } catch (std::exception &e) {
      fprintf(stderr, "Throughput test ends...\n");
    }

    printf("Search throughput: %lf\n", thput);

    std::ofstream ofs;
    ofs.open("throughput_results_search",
             std::ofstream::out | std::ofstream::app);
    ofs << thput << "\n";
    ofs.close();

    return 0;
  }

  int BenchmarkSearchThroughput(uint32_t num_threads) {
    pthread_t thread[num_threads];
    std::vector<BenchmarkData> data;
    fprintf(stderr, "Starting all threads...\n");
    for (uint32_t i = 0; i < num_threads; i++) {
      try {
        BenchmarkData th_data;
        th_data.client = new SuccinctKVClient("localhost");
        th_data.queries = queries_;
        data.push_back(th_data);
      } catch (std::exception& e) {
        fprintf(stderr, "Could not connect to handler on localhost : %s\n",
                e.what());
        return -1;
      }
    }
    fprintf(stderr, "Started %zu clients.\n", data.size());

    for (uint32_t current_t = 0; current_t < num_threads; current_t++) {
      int result = 0;
      result = pthread_create(&thread[current_t], NULL,
                              SuccinctKVBenchmark::SearchThroughput,
                              static_cast<void*>(&(data[current_t])));
      if (result != 0) {
        fprintf(stderr, "Error creating thread %d; return code = %d\n",
                current_t, result);
      }
    }

    for (uint32_t current_t = 0; current_t < num_threads; current_t++) {
      pthread_join(thread[current_t], NULL);
    }
    fprintf(stderr, "All threads completed.\n");

    data.clear();
    return 0;
  }

  static void *GetAndSearchThroughput(void *ptr) {
    BenchmarkData data = *((BenchmarkData*) ptr);
    std::cout << "GET+SEARCH\n";

    SuccinctKVClient client = *(data.client);

    double thput = 0;
    try {
      // Warmup phase
      long i = 0;
      TimeStamp warmup_start = GetTimestamp();
      while (GetTimestamp() - warmup_start < kWarmupTime) {
        if (i % 2 == 0) {
          std::string result;
          client.Get(result, data.randoms[(i / 2) % data.randoms.size()]);
        } else {
          std::set<int64_t> results;
          client.Search(results, data.queries[(i / 2) % data.queries.size()]);
        }
        i++;
      }

      // Measure phase
      long count = 0;
      TimeStamp start = GetTimestamp();
      while (GetTimestamp() - start < kMeasureTime) {
        if (i % 2 == 0) {
          std::string result;
          client.Get(result, data.randoms[(i / 2) % data.randoms.size()]);
        } else {
          std::set<int64_t> results;
          client.Search(results, data.queries[(i / 2) % data.queries.size()]);
        }
        i++; count++;
      }
      TimeStamp end = GetTimestamp();
      double totsecs = (double) (end - start) / (1000.0 * 1000.0);
      thput = ((double) count / totsecs);

      // Cooldown phase
      TimeStamp cooldown_start = GetTimestamp();
      while (GetTimestamp() - cooldown_start < kCooldownTime) {
        if (i % 2 == 0) {
          std::string result;
          client.Get(result, data.randoms[(i / 2) % data.randoms.size()]);
        } else {
          std::set<int64_t> results;
          client.Search(results, data.queries[(i / 2) % data.queries.size()]);
        }
        i++;
      }

    } catch (std::exception &e) {
      fprintf(stderr, "Throughput test ends...\n");
    }

    printf("Get+Search throughput: %lf\n", thput);

    std::ofstream ofs;
    ofs.open("throughput_results_get_search",
             std::ofstream::out | std::ofstream::app);
    ofs << thput << "\n";
    ofs.close();

    return 0;
  }

  int BenchmarkGetAndSearchThroughput(uint32_t num_threads) {
    pthread_t thread[num_threads];
    std::vector<BenchmarkData> data;
    fprintf(stderr, "Starting all threads...\n");
    for (uint32_t i = 0; i < num_threads; i++) {
      try {
        BenchmarkData th_data;
        th_data.client = new SuccinctKVClient("localhost");
        th_data.queries = queries_;
        th_data.randoms = randoms_;
        data.push_back(th_data);
      } catch (std::exception& e) {
        fprintf(stderr, "Could not connect to handler on localhost : %s\n",
                e.what());
        return -1;
      }
    }
    fprintf(stderr, "Started %zu clients.\n", data.size());

    for (uint32_t current_t = 0; current_t < num_threads; current_t++) {
      int result = 0;
      result = pthread_create(&thread[current_t], NULL,
                              SuccinctKVBenchmark::GetAndSearchThroughput,
                              static_cast<void*>(&(data[current_t])));
      if (result != 0) {
        fprintf(stderr, "Error creating thread %d; return code = %d\n",
                current_t, result);
      }
    }

    for (uint32_t current_t = 0; current_t < num_threads; current_t++) {
      pthread_join(thread[current_t], NULL);
    }
    fprintf(stderr, "All threads completed.\n");

    data.clear();
    return 0;
  }

 private:
  typedef struct {
    SuccinctKVClient *client;
    std::vector<int64_t> randoms;
    std::vector<std::string> queries;
    int32_t fetch_length;
  } BenchmarkData;

  static const uint64_t kMaxSum = 10000;

  unsigned long long llrand() {
    unsigned long long r = 0;

    for (int i = 0; i < 5; ++i) {
      r = (r << 15) | (rand() & 0x7FFF);
    }

    return r & 0xFFFFFFFFFFFFFFFFULL;
  }

  void GenerateRandoms() {
    uint64_t query_count = kWarmupCount + kCooldownCount + kMeasureCount;

    // Get #keys for each shard
    uint32_t num_shards = client_->GetNumShards();
    std::vector<int32_t> num_keys;
    for (uint32_t i = 0; i < num_shards; i++) {
      num_keys.push_back(client_->GetNumKeysShard(i));
    }

    fprintf(stderr, "Generating random keys...\n");
    for (uint64_t i = 0; i < query_count; i++) {
      int32_t shard_id = rand() % num_shards;
      int64_t key = shard_id * SuccinctShard::MAX_KEYS
          + rand() % num_keys.at(shard_id);
      randoms_.push_back(key);
    }
    fprintf(stderr, "Generated %llu random keys\n", query_count);
  }

  void ReadQueries(std::string filename) {
    std::ifstream inputfile(filename);
    if (!inputfile.is_open()) {
      fprintf(stderr, "Error: Query file [%s] may be missing.\n",
              filename.c_str());
      return;
    }

    std::string query;
    while (getline(inputfile, query)) {
      queries_.push_back("|" + query + "|");
    }
    inputfile.close();
  }

  std::vector<int64_t> randoms_;
  std::vector<std::string> queries_;
  SuccinctKVClient *client_;
};

#endif
