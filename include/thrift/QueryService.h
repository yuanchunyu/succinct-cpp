/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef QueryService_H
#define QueryService_H

#include <thrift/TDispatchProcessor.h>
#include "thrift/succinct_types.h"



class QueryServiceIf {
 public:
  virtual ~QueryServiceIf() {}
  virtual int32_t init() = 0;
  virtual void extract(std::string& _return, const int64_t offset, const int64_t len) = 0;
  virtual int64_t count(const std::string& query) = 0;
  virtual void search(std::vector<int64_t> & _return, const std::string& query) = 0;
  virtual void wildcard_search(std::vector<int64_t> & _return, const std::string& pattern, const int64_t max_sep) = 0;
};

class QueryServiceIfFactory {
 public:
  typedef QueryServiceIf Handler;

  virtual ~QueryServiceIfFactory() {}

  virtual QueryServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(QueryServiceIf* /* handler */) = 0;
};

class QueryServiceIfSingletonFactory : virtual public QueryServiceIfFactory {
 public:
  QueryServiceIfSingletonFactory(const boost::shared_ptr<QueryServiceIf>& iface) : iface_(iface) {}
  virtual ~QueryServiceIfSingletonFactory() {}

  virtual QueryServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(QueryServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<QueryServiceIf> iface_;
};

class QueryServiceNull : virtual public QueryServiceIf {
 public:
  virtual ~QueryServiceNull() {}
  int32_t init() {
    int32_t _return = 0;
    return _return;
  }
  void extract(std::string& /* _return */, const int64_t /* offset */, const int64_t /* len */) {
    return;
  }
  int64_t count(const std::string& /* query */) {
    int64_t _return = 0;
    return _return;
  }
  void search(std::vector<int64_t> & /* _return */, const std::string& /* query */) {
    return;
  }
  void wildcard_search(std::vector<int64_t> & /* _return */, const std::string& /* pattern */, const int64_t /* max_sep */) {
    return;
  }
};


class QueryService_init_args {
 public:

  QueryService_init_args() {
  }

  virtual ~QueryService_init_args() throw() {}


  bool operator == (const QueryService_init_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const QueryService_init_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_init_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QueryService_init_pargs {
 public:


  virtual ~QueryService_init_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_init_result__isset {
  _QueryService_init_result__isset() : success(false) {}
  bool success;
} _QueryService_init_result__isset;

class QueryService_init_result {
 public:

  QueryService_init_result() : success(0) {
  }

  virtual ~QueryService_init_result() throw() {}

  int32_t success;

  _QueryService_init_result__isset __isset;

  void __set_success(const int32_t val) {
    success = val;
  }

  bool operator == (const QueryService_init_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QueryService_init_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_init_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_init_presult__isset {
  _QueryService_init_presult__isset() : success(false) {}
  bool success;
} _QueryService_init_presult__isset;

class QueryService_init_presult {
 public:


  virtual ~QueryService_init_presult() throw() {}

  int32_t* success;

  _QueryService_init_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _QueryService_extract_args__isset {
  _QueryService_extract_args__isset() : offset(false), len(false) {}
  bool offset;
  bool len;
} _QueryService_extract_args__isset;

class QueryService_extract_args {
 public:

  QueryService_extract_args() : offset(0), len(0) {
  }

  virtual ~QueryService_extract_args() throw() {}

  int64_t offset;
  int64_t len;

  _QueryService_extract_args__isset __isset;

  void __set_offset(const int64_t val) {
    offset = val;
  }

  void __set_len(const int64_t val) {
    len = val;
  }

  bool operator == (const QueryService_extract_args & rhs) const
  {
    if (!(offset == rhs.offset))
      return false;
    if (!(len == rhs.len))
      return false;
    return true;
  }
  bool operator != (const QueryService_extract_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_extract_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QueryService_extract_pargs {
 public:


  virtual ~QueryService_extract_pargs() throw() {}

  const int64_t* offset;
  const int64_t* len;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_extract_result__isset {
  _QueryService_extract_result__isset() : success(false) {}
  bool success;
} _QueryService_extract_result__isset;

class QueryService_extract_result {
 public:

  QueryService_extract_result() : success() {
  }

  virtual ~QueryService_extract_result() throw() {}

  std::string success;

  _QueryService_extract_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const QueryService_extract_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QueryService_extract_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_extract_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_extract_presult__isset {
  _QueryService_extract_presult__isset() : success(false) {}
  bool success;
} _QueryService_extract_presult__isset;

class QueryService_extract_presult {
 public:


  virtual ~QueryService_extract_presult() throw() {}

  std::string* success;

  _QueryService_extract_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _QueryService_count_args__isset {
  _QueryService_count_args__isset() : query(false) {}
  bool query;
} _QueryService_count_args__isset;

class QueryService_count_args {
 public:

  QueryService_count_args() : query() {
  }

  virtual ~QueryService_count_args() throw() {}

  std::string query;

  _QueryService_count_args__isset __isset;

  void __set_query(const std::string& val) {
    query = val;
  }

  bool operator == (const QueryService_count_args & rhs) const
  {
    if (!(query == rhs.query))
      return false;
    return true;
  }
  bool operator != (const QueryService_count_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_count_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QueryService_count_pargs {
 public:


  virtual ~QueryService_count_pargs() throw() {}

  const std::string* query;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_count_result__isset {
  _QueryService_count_result__isset() : success(false) {}
  bool success;
} _QueryService_count_result__isset;

class QueryService_count_result {
 public:

  QueryService_count_result() : success(0) {
  }

  virtual ~QueryService_count_result() throw() {}

  int64_t success;

  _QueryService_count_result__isset __isset;

  void __set_success(const int64_t val) {
    success = val;
  }

  bool operator == (const QueryService_count_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QueryService_count_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_count_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_count_presult__isset {
  _QueryService_count_presult__isset() : success(false) {}
  bool success;
} _QueryService_count_presult__isset;

class QueryService_count_presult {
 public:


  virtual ~QueryService_count_presult() throw() {}

  int64_t* success;

  _QueryService_count_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _QueryService_search_args__isset {
  _QueryService_search_args__isset() : query(false) {}
  bool query;
} _QueryService_search_args__isset;

class QueryService_search_args {
 public:

  QueryService_search_args() : query() {
  }

  virtual ~QueryService_search_args() throw() {}

  std::string query;

  _QueryService_search_args__isset __isset;

  void __set_query(const std::string& val) {
    query = val;
  }

  bool operator == (const QueryService_search_args & rhs) const
  {
    if (!(query == rhs.query))
      return false;
    return true;
  }
  bool operator != (const QueryService_search_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_search_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QueryService_search_pargs {
 public:


  virtual ~QueryService_search_pargs() throw() {}

  const std::string* query;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_search_result__isset {
  _QueryService_search_result__isset() : success(false) {}
  bool success;
} _QueryService_search_result__isset;

class QueryService_search_result {
 public:

  QueryService_search_result() {
  }

  virtual ~QueryService_search_result() throw() {}

  std::vector<int64_t>  success;

  _QueryService_search_result__isset __isset;

  void __set_success(const std::vector<int64_t> & val) {
    success = val;
  }

  bool operator == (const QueryService_search_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QueryService_search_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_search_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_search_presult__isset {
  _QueryService_search_presult__isset() : success(false) {}
  bool success;
} _QueryService_search_presult__isset;

class QueryService_search_presult {
 public:


  virtual ~QueryService_search_presult() throw() {}

  std::vector<int64_t> * success;

  _QueryService_search_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _QueryService_wildcard_search_args__isset {
  _QueryService_wildcard_search_args__isset() : pattern(false), max_sep(false) {}
  bool pattern;
  bool max_sep;
} _QueryService_wildcard_search_args__isset;

class QueryService_wildcard_search_args {
 public:

  QueryService_wildcard_search_args() : pattern(), max_sep(0) {
  }

  virtual ~QueryService_wildcard_search_args() throw() {}

  std::string pattern;
  int64_t max_sep;

  _QueryService_wildcard_search_args__isset __isset;

  void __set_pattern(const std::string& val) {
    pattern = val;
  }

  void __set_max_sep(const int64_t val) {
    max_sep = val;
  }

  bool operator == (const QueryService_wildcard_search_args & rhs) const
  {
    if (!(pattern == rhs.pattern))
      return false;
    if (!(max_sep == rhs.max_sep))
      return false;
    return true;
  }
  bool operator != (const QueryService_wildcard_search_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_wildcard_search_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QueryService_wildcard_search_pargs {
 public:


  virtual ~QueryService_wildcard_search_pargs() throw() {}

  const std::string* pattern;
  const int64_t* max_sep;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_wildcard_search_result__isset {
  _QueryService_wildcard_search_result__isset() : success(false) {}
  bool success;
} _QueryService_wildcard_search_result__isset;

class QueryService_wildcard_search_result {
 public:

  QueryService_wildcard_search_result() {
  }

  virtual ~QueryService_wildcard_search_result() throw() {}

  std::vector<int64_t>  success;

  _QueryService_wildcard_search_result__isset __isset;

  void __set_success(const std::vector<int64_t> & val) {
    success = val;
  }

  bool operator == (const QueryService_wildcard_search_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QueryService_wildcard_search_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QueryService_wildcard_search_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QueryService_wildcard_search_presult__isset {
  _QueryService_wildcard_search_presult__isset() : success(false) {}
  bool success;
} _QueryService_wildcard_search_presult__isset;

class QueryService_wildcard_search_presult {
 public:


  virtual ~QueryService_wildcard_search_presult() throw() {}

  std::vector<int64_t> * success;

  _QueryService_wildcard_search_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class QueryServiceClient : virtual public QueryServiceIf {
 public:
  QueryServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  QueryServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t init();
  void send_init();
  int32_t recv_init();
  void extract(std::string& _return, const int64_t offset, const int64_t len);
  void send_extract(const int64_t offset, const int64_t len);
  void recv_extract(std::string& _return);
  int64_t count(const std::string& query);
  void send_count(const std::string& query);
  int64_t recv_count();
  void search(std::vector<int64_t> & _return, const std::string& query);
  void send_search(const std::string& query);
  void recv_search(std::vector<int64_t> & _return);
  void wildcard_search(std::vector<int64_t> & _return, const std::string& pattern, const int64_t max_sep);
  void send_wildcard_search(const std::string& pattern, const int64_t max_sep);
  void recv_wildcard_search(std::vector<int64_t> & _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class QueryServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<QueryServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (QueryServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_init(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_extract(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_count(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_search(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_wildcard_search(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  QueryServiceProcessor(boost::shared_ptr<QueryServiceIf> iface) :
    iface_(iface) {
    processMap_["init"] = &QueryServiceProcessor::process_init;
    processMap_["extract"] = &QueryServiceProcessor::process_extract;
    processMap_["count"] = &QueryServiceProcessor::process_count;
    processMap_["search"] = &QueryServiceProcessor::process_search;
    processMap_["wildcard_search"] = &QueryServiceProcessor::process_wildcard_search;
  }

  virtual ~QueryServiceProcessor() {}
};

class QueryServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  QueryServiceProcessorFactory(const ::boost::shared_ptr< QueryServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< QueryServiceIfFactory > handlerFactory_;
};

class QueryServiceMultiface : virtual public QueryServiceIf {
 public:
  QueryServiceMultiface(std::vector<boost::shared_ptr<QueryServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~QueryServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<QueryServiceIf> > ifaces_;
  QueryServiceMultiface() {}
  void add(boost::shared_ptr<QueryServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int32_t init() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->init();
    }
    return ifaces_[i]->init();
  }

  void extract(std::string& _return, const int64_t offset, const int64_t len) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->extract(_return, offset, len);
    }
    ifaces_[i]->extract(_return, offset, len);
    return;
  }

  int64_t count(const std::string& query) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->count(query);
    }
    return ifaces_[i]->count(query);
  }

  void search(std::vector<int64_t> & _return, const std::string& query) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->search(_return, query);
    }
    ifaces_[i]->search(_return, query);
    return;
  }

  void wildcard_search(std::vector<int64_t> & _return, const std::string& pattern, const int64_t max_sep) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->wildcard_search(_return, pattern, max_sep);
    }
    ifaces_[i]->wildcard_search(_return, pattern, max_sep);
    return;
  }

};



#endif
