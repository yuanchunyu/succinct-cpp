/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef AggregatorService_H
#define AggregatorService_H

#include <thrift/TDispatchProcessor.h>
#include "succinct_types.h"



class AggregatorServiceIf {
 public:
  virtual ~AggregatorServiceIf() {}
  virtual int32_t ConnectToServers() = 0;
  virtual int32_t DisconnectFromServers() = 0;
  virtual int32_t Initialize() = 0;
  virtual void Regex(std::set<int64_t> & _return, const std::string& query) = 0;
  virtual void Extract(std::string& _return, const int64_t offset, const int64_t length) = 0;
  virtual int64_t Count(const std::string& query) = 0;
  virtual void Search(std::vector<int64_t> & _return, const std::string& query) = 0;
  virtual int32_t GetNumShards() = 0;
  virtual int64_t GetTotSize() = 0;
};

class AggregatorServiceIfFactory {
 public:
  typedef AggregatorServiceIf Handler;

  virtual ~AggregatorServiceIfFactory() {}

  virtual AggregatorServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(AggregatorServiceIf* /* handler */) = 0;
};

class AggregatorServiceIfSingletonFactory : virtual public AggregatorServiceIfFactory {
 public:
  AggregatorServiceIfSingletonFactory(const boost::shared_ptr<AggregatorServiceIf>& iface) : iface_(iface) {}
  virtual ~AggregatorServiceIfSingletonFactory() {}

  virtual AggregatorServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(AggregatorServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<AggregatorServiceIf> iface_;
};

class AggregatorServiceNull : virtual public AggregatorServiceIf {
 public:
  virtual ~AggregatorServiceNull() {}
  int32_t ConnectToServers() {
    int32_t _return = 0;
    return _return;
  }
  int32_t DisconnectFromServers() {
    int32_t _return = 0;
    return _return;
  }
  int32_t Initialize() {
    int32_t _return = 0;
    return _return;
  }
  void Regex(std::set<int64_t> & /* _return */, const std::string& /* query */) {
    return;
  }
  void Extract(std::string& /* _return */, const int64_t /* offset */, const int64_t /* length */) {
    return;
  }
  int64_t Count(const std::string& /* query */) {
    int64_t _return = 0;
    return _return;
  }
  void Search(std::vector<int64_t> & /* _return */, const std::string& /* query */) {
    return;
  }
  int32_t GetNumShards() {
    int32_t _return = 0;
    return _return;
  }
  int64_t GetTotSize() {
    int64_t _return = 0;
    return _return;
  }
};


class AggregatorService_ConnectToServers_args {
 public:

  AggregatorService_ConnectToServers_args() {
  }

  virtual ~AggregatorService_ConnectToServers_args() throw() {}


  bool operator == (const AggregatorService_ConnectToServers_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const AggregatorService_ConnectToServers_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AggregatorService_ConnectToServers_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AggregatorService_ConnectToServers_pargs {
 public:


  virtual ~AggregatorService_ConnectToServers_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AggregatorService_ConnectToServers_result__isset {
  _AggregatorService_ConnectToServers_result__isset() : success(false) {}
  bool success;
} _AggregatorService_ConnectToServers_result__isset;

class AggregatorService_ConnectToServers_result {
 public:

  AggregatorService_ConnectToServers_result() : success(0) {
  }

  virtual ~AggregatorService_ConnectToServers_result() throw() {}

  int32_t success;

  _AggregatorService_ConnectToServers_result__isset __isset;

  void __set_success(const int32_t val) {
    success = val;
  }

  bool operator == (const AggregatorService_ConnectToServers_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const AggregatorService_ConnectToServers_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AggregatorService_ConnectToServers_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AggregatorService_ConnectToServers_presult__isset {
  _AggregatorService_ConnectToServers_presult__isset() : success(false) {}
  bool success;
} _AggregatorService_ConnectToServers_presult__isset;

class AggregatorService_ConnectToServers_presult {
 public:


  virtual ~AggregatorService_ConnectToServers_presult() throw() {}

  int32_t* success;

  _AggregatorService_ConnectToServers_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class AggregatorService_DisconnectFromServers_args {
 public:

  AggregatorService_DisconnectFromServers_args() {
  }

  virtual ~AggregatorService_DisconnectFromServers_args() throw() {}


  bool operator == (const AggregatorService_DisconnectFromServers_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const AggregatorService_DisconnectFromServers_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AggregatorService_DisconnectFromServers_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AggregatorService_DisconnectFromServers_pargs {
 public:


  virtual ~AggregatorService_DisconnectFromServers_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AggregatorService_DisconnectFromServers_result__isset {
  _AggregatorService_DisconnectFromServers_result__isset() : success(false) {}
  bool success;
} _AggregatorService_DisconnectFromServers_result__isset;

class AggregatorService_DisconnectFromServers_result {
 public:

  AggregatorService_DisconnectFromServers_result() : success(0) {
  }

  virtual ~AggregatorService_DisconnectFromServers_result() throw() {}

  int32_t success;

  _AggregatorService_DisconnectFromServers_result__isset __isset;

  void __set_success(const int32_t val) {
    success = val;
  }

  bool operator == (const AggregatorService_DisconnectFromServers_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const AggregatorService_DisconnectFromServers_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AggregatorService_DisconnectFromServers_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AggregatorService_DisconnectFromServers_presult__isset {
  _AggregatorService_DisconnectFromServers_presult__isset() : success(false) {}
  bool success;
} _AggregatorService_DisconnectFromServers_presult__isset;

class AggregatorService_DisconnectFromServers_presult {
 public:


  virtual ~AggregatorService_DisconnectFromServers_presult() throw() {}

  int32_t* success;

  _AggregatorService_DisconnectFromServers_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class AggregatorService_Initialize_args {
 public:

  AggregatorService_Initialize_args() {
  }

  virtual ~AggregatorService_Initialize_args() throw() {}


  bool operator == (const AggregatorService_Initialize_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const AggregatorService_Initialize_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AggregatorService_Initialize_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AggregatorService_Initialize_pargs {
 public:


  virtual ~AggregatorService_Initialize_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AggregatorService_Initialize_result__isset {
  _AggregatorService_Initialize_result__isset() : success(false) {}
  bool success;
} _AggregatorService_Initialize_result__isset;

class AggregatorService_Initialize_result {
 public:

  AggregatorService_Initialize_result() : success(0) {
  }

  virtual ~AggregatorService_Initialize_result() throw() {}

  int32_t success;

  _AggregatorService_Initialize_result__isset __isset;

  void __set_success(const int32_t val) {
    success = val;
  }

  bool operator == (const AggregatorService_Initialize_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const AggregatorService_Initialize_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AggregatorService_Initialize_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AggregatorService_Initialize_presult__isset {
  _AggregatorService_Initialize_presult__isset() : success(false) {}
  bool success;
} _AggregatorService_Initialize_presult__isset;

class AggregatorService_Initialize_presult {
 public:


  virtual ~AggregatorService_Initialize_presult() throw() {}

  int32_t* success;

  _AggregatorService_Initialize_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _AggregatorService_Regex_args__isset {
  _AggregatorService_Regex_args__isset() : query(false) {}
  bool query;
} _AggregatorService_Regex_args__isset;

class AggregatorService_Regex_args {
 public:

  AggregatorService_Regex_args() : query() {
  }

  virtual ~AggregatorService_Regex_args() throw() {}

  std::string query;

  _AggregatorService_Regex_args__isset __isset;

  void __set_query(const std::string& val) {
    query = val;
  }

  bool operator == (const AggregatorService_Regex_args & rhs) const
  {
    if (!(query == rhs.query))
      return false;
    return true;
  }
  bool operator != (const AggregatorService_Regex_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AggregatorService_Regex_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AggregatorService_Regex_pargs {
 public:


  virtual ~AggregatorService_Regex_pargs() throw() {}

  const std::string* query;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AggregatorService_Regex_result__isset {
  _AggregatorService_Regex_result__isset() : success(false) {}
  bool success;
} _AggregatorService_Regex_result__isset;

class AggregatorService_Regex_result {
 public:

  AggregatorService_Regex_result() {
  }

  virtual ~AggregatorService_Regex_result() throw() {}

  std::set<int64_t>  success;

  _AggregatorService_Regex_result__isset __isset;

  void __set_success(const std::set<int64_t> & val) {
    success = val;
  }

  bool operator == (const AggregatorService_Regex_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const AggregatorService_Regex_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AggregatorService_Regex_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AggregatorService_Regex_presult__isset {
  _AggregatorService_Regex_presult__isset() : success(false) {}
  bool success;
} _AggregatorService_Regex_presult__isset;

class AggregatorService_Regex_presult {
 public:


  virtual ~AggregatorService_Regex_presult() throw() {}

  std::set<int64_t> * success;

  _AggregatorService_Regex_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _AggregatorService_Extract_args__isset {
  _AggregatorService_Extract_args__isset() : offset(false), length(false) {}
  bool offset;
  bool length;
} _AggregatorService_Extract_args__isset;

class AggregatorService_Extract_args {
 public:

  AggregatorService_Extract_args() : offset(0), length(0) {
  }

  virtual ~AggregatorService_Extract_args() throw() {}

  int64_t offset;
  int64_t length;

  _AggregatorService_Extract_args__isset __isset;

  void __set_offset(const int64_t val) {
    offset = val;
  }

  void __set_length(const int64_t val) {
    length = val;
  }

  bool operator == (const AggregatorService_Extract_args & rhs) const
  {
    if (!(offset == rhs.offset))
      return false;
    if (!(length == rhs.length))
      return false;
    return true;
  }
  bool operator != (const AggregatorService_Extract_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AggregatorService_Extract_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AggregatorService_Extract_pargs {
 public:


  virtual ~AggregatorService_Extract_pargs() throw() {}

  const int64_t* offset;
  const int64_t* length;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AggregatorService_Extract_result__isset {
  _AggregatorService_Extract_result__isset() : success(false) {}
  bool success;
} _AggregatorService_Extract_result__isset;

class AggregatorService_Extract_result {
 public:

  AggregatorService_Extract_result() : success() {
  }

  virtual ~AggregatorService_Extract_result() throw() {}

  std::string success;

  _AggregatorService_Extract_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const AggregatorService_Extract_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const AggregatorService_Extract_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AggregatorService_Extract_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AggregatorService_Extract_presult__isset {
  _AggregatorService_Extract_presult__isset() : success(false) {}
  bool success;
} _AggregatorService_Extract_presult__isset;

class AggregatorService_Extract_presult {
 public:


  virtual ~AggregatorService_Extract_presult() throw() {}

  std::string* success;

  _AggregatorService_Extract_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _AggregatorService_Count_args__isset {
  _AggregatorService_Count_args__isset() : query(false) {}
  bool query;
} _AggregatorService_Count_args__isset;

class AggregatorService_Count_args {
 public:

  AggregatorService_Count_args() : query() {
  }

  virtual ~AggregatorService_Count_args() throw() {}

  std::string query;

  _AggregatorService_Count_args__isset __isset;

  void __set_query(const std::string& val) {
    query = val;
  }

  bool operator == (const AggregatorService_Count_args & rhs) const
  {
    if (!(query == rhs.query))
      return false;
    return true;
  }
  bool operator != (const AggregatorService_Count_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AggregatorService_Count_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AggregatorService_Count_pargs {
 public:


  virtual ~AggregatorService_Count_pargs() throw() {}

  const std::string* query;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AggregatorService_Count_result__isset {
  _AggregatorService_Count_result__isset() : success(false) {}
  bool success;
} _AggregatorService_Count_result__isset;

class AggregatorService_Count_result {
 public:

  AggregatorService_Count_result() : success(0) {
  }

  virtual ~AggregatorService_Count_result() throw() {}

  int64_t success;

  _AggregatorService_Count_result__isset __isset;

  void __set_success(const int64_t val) {
    success = val;
  }

  bool operator == (const AggregatorService_Count_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const AggregatorService_Count_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AggregatorService_Count_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AggregatorService_Count_presult__isset {
  _AggregatorService_Count_presult__isset() : success(false) {}
  bool success;
} _AggregatorService_Count_presult__isset;

class AggregatorService_Count_presult {
 public:


  virtual ~AggregatorService_Count_presult() throw() {}

  int64_t* success;

  _AggregatorService_Count_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _AggregatorService_Search_args__isset {
  _AggregatorService_Search_args__isset() : query(false) {}
  bool query;
} _AggregatorService_Search_args__isset;

class AggregatorService_Search_args {
 public:

  AggregatorService_Search_args() : query() {
  }

  virtual ~AggregatorService_Search_args() throw() {}

  std::string query;

  _AggregatorService_Search_args__isset __isset;

  void __set_query(const std::string& val) {
    query = val;
  }

  bool operator == (const AggregatorService_Search_args & rhs) const
  {
    if (!(query == rhs.query))
      return false;
    return true;
  }
  bool operator != (const AggregatorService_Search_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AggregatorService_Search_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AggregatorService_Search_pargs {
 public:


  virtual ~AggregatorService_Search_pargs() throw() {}

  const std::string* query;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AggregatorService_Search_result__isset {
  _AggregatorService_Search_result__isset() : success(false) {}
  bool success;
} _AggregatorService_Search_result__isset;

class AggregatorService_Search_result {
 public:

  AggregatorService_Search_result() {
  }

  virtual ~AggregatorService_Search_result() throw() {}

  std::vector<int64_t>  success;

  _AggregatorService_Search_result__isset __isset;

  void __set_success(const std::vector<int64_t> & val) {
    success = val;
  }

  bool operator == (const AggregatorService_Search_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const AggregatorService_Search_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AggregatorService_Search_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AggregatorService_Search_presult__isset {
  _AggregatorService_Search_presult__isset() : success(false) {}
  bool success;
} _AggregatorService_Search_presult__isset;

class AggregatorService_Search_presult {
 public:


  virtual ~AggregatorService_Search_presult() throw() {}

  std::vector<int64_t> * success;

  _AggregatorService_Search_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class AggregatorService_GetNumShards_args {
 public:

  AggregatorService_GetNumShards_args() {
  }

  virtual ~AggregatorService_GetNumShards_args() throw() {}


  bool operator == (const AggregatorService_GetNumShards_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const AggregatorService_GetNumShards_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AggregatorService_GetNumShards_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AggregatorService_GetNumShards_pargs {
 public:


  virtual ~AggregatorService_GetNumShards_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AggregatorService_GetNumShards_result__isset {
  _AggregatorService_GetNumShards_result__isset() : success(false) {}
  bool success;
} _AggregatorService_GetNumShards_result__isset;

class AggregatorService_GetNumShards_result {
 public:

  AggregatorService_GetNumShards_result() : success(0) {
  }

  virtual ~AggregatorService_GetNumShards_result() throw() {}

  int32_t success;

  _AggregatorService_GetNumShards_result__isset __isset;

  void __set_success(const int32_t val) {
    success = val;
  }

  bool operator == (const AggregatorService_GetNumShards_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const AggregatorService_GetNumShards_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AggregatorService_GetNumShards_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AggregatorService_GetNumShards_presult__isset {
  _AggregatorService_GetNumShards_presult__isset() : success(false) {}
  bool success;
} _AggregatorService_GetNumShards_presult__isset;

class AggregatorService_GetNumShards_presult {
 public:


  virtual ~AggregatorService_GetNumShards_presult() throw() {}

  int32_t* success;

  _AggregatorService_GetNumShards_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class AggregatorService_GetTotSize_args {
 public:

  AggregatorService_GetTotSize_args() {
  }

  virtual ~AggregatorService_GetTotSize_args() throw() {}


  bool operator == (const AggregatorService_GetTotSize_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const AggregatorService_GetTotSize_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AggregatorService_GetTotSize_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class AggregatorService_GetTotSize_pargs {
 public:


  virtual ~AggregatorService_GetTotSize_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AggregatorService_GetTotSize_result__isset {
  _AggregatorService_GetTotSize_result__isset() : success(false) {}
  bool success;
} _AggregatorService_GetTotSize_result__isset;

class AggregatorService_GetTotSize_result {
 public:

  AggregatorService_GetTotSize_result() : success(0) {
  }

  virtual ~AggregatorService_GetTotSize_result() throw() {}

  int64_t success;

  _AggregatorService_GetTotSize_result__isset __isset;

  void __set_success(const int64_t val) {
    success = val;
  }

  bool operator == (const AggregatorService_GetTotSize_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const AggregatorService_GetTotSize_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AggregatorService_GetTotSize_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AggregatorService_GetTotSize_presult__isset {
  _AggregatorService_GetTotSize_presult__isset() : success(false) {}
  bool success;
} _AggregatorService_GetTotSize_presult__isset;

class AggregatorService_GetTotSize_presult {
 public:


  virtual ~AggregatorService_GetTotSize_presult() throw() {}

  int64_t* success;

  _AggregatorService_GetTotSize_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class AggregatorServiceClient : virtual public AggregatorServiceIf {
 public:
  AggregatorServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  AggregatorServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
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
  int32_t ConnectToServers();
  void send_ConnectToServers();
  int32_t recv_ConnectToServers();
  int32_t DisconnectFromServers();
  void send_DisconnectFromServers();
  int32_t recv_DisconnectFromServers();
  int32_t Initialize();
  void send_Initialize();
  int32_t recv_Initialize();
  void Regex(std::set<int64_t> & _return, const std::string& query);
  void send_Regex(const std::string& query);
  void recv_Regex(std::set<int64_t> & _return);
  void Extract(std::string& _return, const int64_t offset, const int64_t length);
  void send_Extract(const int64_t offset, const int64_t length);
  void recv_Extract(std::string& _return);
  int64_t Count(const std::string& query);
  void send_Count(const std::string& query);
  int64_t recv_Count();
  void Search(std::vector<int64_t> & _return, const std::string& query);
  void send_Search(const std::string& query);
  void recv_Search(std::vector<int64_t> & _return);
  int32_t GetNumShards();
  void send_GetNumShards();
  int32_t recv_GetNumShards();
  int64_t GetTotSize();
  void send_GetTotSize();
  int64_t recv_GetTotSize();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class AggregatorServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<AggregatorServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (AggregatorServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_ConnectToServers(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_DisconnectFromServers(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Initialize(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Regex(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Extract(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Count(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Search(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_GetNumShards(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_GetTotSize(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  AggregatorServiceProcessor(boost::shared_ptr<AggregatorServiceIf> iface) :
    iface_(iface) {
    processMap_["ConnectToServers"] = &AggregatorServiceProcessor::process_ConnectToServers;
    processMap_["DisconnectFromServers"] = &AggregatorServiceProcessor::process_DisconnectFromServers;
    processMap_["Initialize"] = &AggregatorServiceProcessor::process_Initialize;
    processMap_["Regex"] = &AggregatorServiceProcessor::process_Regex;
    processMap_["Extract"] = &AggregatorServiceProcessor::process_Extract;
    processMap_["Count"] = &AggregatorServiceProcessor::process_Count;
    processMap_["Search"] = &AggregatorServiceProcessor::process_Search;
    processMap_["GetNumShards"] = &AggregatorServiceProcessor::process_GetNumShards;
    processMap_["GetTotSize"] = &AggregatorServiceProcessor::process_GetTotSize;
  }

  virtual ~AggregatorServiceProcessor() {}
};

class AggregatorServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  AggregatorServiceProcessorFactory(const ::boost::shared_ptr< AggregatorServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< AggregatorServiceIfFactory > handlerFactory_;
};

class AggregatorServiceMultiface : virtual public AggregatorServiceIf {
 public:
  AggregatorServiceMultiface(std::vector<boost::shared_ptr<AggregatorServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~AggregatorServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<AggregatorServiceIf> > ifaces_;
  AggregatorServiceMultiface() {}
  void add(boost::shared_ptr<AggregatorServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int32_t ConnectToServers() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->ConnectToServers();
    }
    return ifaces_[i]->ConnectToServers();
  }

  int32_t DisconnectFromServers() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->DisconnectFromServers();
    }
    return ifaces_[i]->DisconnectFromServers();
  }

  int32_t Initialize() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Initialize();
    }
    return ifaces_[i]->Initialize();
  }

  void Regex(std::set<int64_t> & _return, const std::string& query) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Regex(_return, query);
    }
    ifaces_[i]->Regex(_return, query);
    return;
  }

  void Extract(std::string& _return, const int64_t offset, const int64_t length) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Extract(_return, offset, length);
    }
    ifaces_[i]->Extract(_return, offset, length);
    return;
  }

  int64_t Count(const std::string& query) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Count(query);
    }
    return ifaces_[i]->Count(query);
  }

  void Search(std::vector<int64_t> & _return, const std::string& query) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Search(_return, query);
    }
    ifaces_[i]->Search(_return, query);
    return;
  }

  int32_t GetNumShards() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->GetNumShards();
    }
    return ifaces_[i]->GetNumShards();
  }

  int64_t GetTotSize() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->GetTotSize();
    }
    return ifaces_[i]->GetTotSize();
  }

};



#endif
