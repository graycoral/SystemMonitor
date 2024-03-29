// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: system_monitor.proto
// Protobuf C++ Version: 4.25.1

#ifndef GOOGLE_PROTOBUF_INCLUDED_system_5fmonitor_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_system_5fmonitor_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4025000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4025001 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_bases.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_system_5fmonitor_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_system_5fmonitor_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_system_5fmonitor_2eproto;
namespace systemmonitor {
class CpuUsageRequest;
struct CpuUsageRequestDefaultTypeInternal;
extern CpuUsageRequestDefaultTypeInternal _CpuUsageRequest_default_instance_;
class CpuUsageResponse;
struct CpuUsageResponseDefaultTypeInternal;
extern CpuUsageResponseDefaultTypeInternal _CpuUsageResponse_default_instance_;
}  // namespace systemmonitor
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace systemmonitor {

// ===================================================================


// -------------------------------------------------------------------

class CpuUsageResponse final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:systemmonitor.CpuUsageResponse) */ {
 public:
  inline CpuUsageResponse() : CpuUsageResponse(nullptr) {}
  ~CpuUsageResponse() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR CpuUsageResponse(::google::protobuf::internal::ConstantInitialized);

  inline CpuUsageResponse(const CpuUsageResponse& from)
      : CpuUsageResponse(nullptr, from) {}
  CpuUsageResponse(CpuUsageResponse&& from) noexcept
    : CpuUsageResponse() {
    *this = ::std::move(from);
  }

  inline CpuUsageResponse& operator=(const CpuUsageResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline CpuUsageResponse& operator=(CpuUsageResponse&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const CpuUsageResponse& default_instance() {
    return *internal_default_instance();
  }
  static inline const CpuUsageResponse* internal_default_instance() {
    return reinterpret_cast<const CpuUsageResponse*>(
               &_CpuUsageResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(CpuUsageResponse& a, CpuUsageResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(CpuUsageResponse* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr &&
        GetArena() == other->GetArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(CpuUsageResponse* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  CpuUsageResponse* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<CpuUsageResponse>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const CpuUsageResponse& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const CpuUsageResponse& from) {
    CpuUsageResponse::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  ::google::protobuf::internal::CachedSize* AccessCachedSize() const final;
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(CpuUsageResponse* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "systemmonitor.CpuUsageResponse";
  }
  protected:
  explicit CpuUsageResponse(::google::protobuf::Arena* arena);
  CpuUsageResponse(::google::protobuf::Arena* arena, const CpuUsageResponse& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kUsagePercentFieldNumber = 1,
  };
  // float usage_percent = 1;
  void clear_usage_percent() ;
  float usage_percent() const;
  void set_usage_percent(float value);

  private:
  float _internal_usage_percent() const;
  void _internal_set_usage_percent(float value);

  public:
  // @@protoc_insertion_point(class_scope:systemmonitor.CpuUsageResponse)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 0,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {

        inline explicit constexpr Impl_(
            ::google::protobuf::internal::ConstantInitialized) noexcept;
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena);
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena, const Impl_& from);
    float usage_percent_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_system_5fmonitor_2eproto;
};// -------------------------------------------------------------------

class CpuUsageRequest final :
    public ::google::protobuf::internal::ZeroFieldsBase /* @@protoc_insertion_point(class_definition:systemmonitor.CpuUsageRequest) */ {
 public:
  inline CpuUsageRequest() : CpuUsageRequest(nullptr) {}
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR CpuUsageRequest(::google::protobuf::internal::ConstantInitialized);

  inline CpuUsageRequest(const CpuUsageRequest& from)
      : CpuUsageRequest(nullptr, from) {}
  CpuUsageRequest(CpuUsageRequest&& from) noexcept
    : CpuUsageRequest() {
    *this = ::std::move(from);
  }

  inline CpuUsageRequest& operator=(const CpuUsageRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline CpuUsageRequest& operator=(CpuUsageRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const CpuUsageRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const CpuUsageRequest* internal_default_instance() {
    return reinterpret_cast<const CpuUsageRequest*>(
               &_CpuUsageRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(CpuUsageRequest& a, CpuUsageRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(CpuUsageRequest* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr &&
        GetArena() == other->GetArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(CpuUsageRequest* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  CpuUsageRequest* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<CpuUsageRequest>(arena);
  }
  using ::google::protobuf::internal::ZeroFieldsBase::CopyFrom;
  inline void CopyFrom(const CpuUsageRequest& from) {
    ::google::protobuf::internal::ZeroFieldsBase::CopyImpl(*this, from);
  }
  using ::google::protobuf::internal::ZeroFieldsBase::MergeFrom;
  void MergeFrom(const CpuUsageRequest& from) {
    ::google::protobuf::internal::ZeroFieldsBase::MergeImpl(*this, from);
  }
  public:

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "systemmonitor.CpuUsageRequest";
  }
  protected:
  explicit CpuUsageRequest(::google::protobuf::Arena* arena);
  CpuUsageRequest(::google::protobuf::Arena* arena, const CpuUsageRequest& from);
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:systemmonitor.CpuUsageRequest)
 private:
  class _Internal;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {

        inline explicit constexpr Impl_(
            ::google::protobuf::internal::ConstantInitialized) noexcept;
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena);
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena, const Impl_& from);
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  friend struct ::TableStruct_system_5fmonitor_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// CpuUsageRequest

// -------------------------------------------------------------------

// CpuUsageResponse

// float usage_percent = 1;
inline void CpuUsageResponse::clear_usage_percent() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.usage_percent_ = 0;
}
inline float CpuUsageResponse::usage_percent() const {
  // @@protoc_insertion_point(field_get:systemmonitor.CpuUsageResponse.usage_percent)
  return _internal_usage_percent();
}
inline void CpuUsageResponse::set_usage_percent(float value) {
  _internal_set_usage_percent(value);
  // @@protoc_insertion_point(field_set:systemmonitor.CpuUsageResponse.usage_percent)
}
inline float CpuUsageResponse::_internal_usage_percent() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.usage_percent_;
}
inline void CpuUsageResponse::_internal_set_usage_percent(float value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.usage_percent_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace systemmonitor


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_system_5fmonitor_2eproto_2epb_2eh
