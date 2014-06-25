// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: BaseAttr.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "BaseAttr.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* BaseAttr_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  BaseAttr_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* BaseAttr_ePart_descriptor_ = NULL;
const ::google::protobuf::EnumDescriptor* BaseAttr_eQuality_descriptor_ = NULL;
const ::google::protobuf::EnumDescriptor* BaseAttr_eQualityRank_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_BaseAttr_2eproto() {
  protobuf_AddDesc_BaseAttr_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "BaseAttr.proto");
  GOOGLE_CHECK(file != NULL);
  BaseAttr_descriptor_ = file->message_type(0);
  static const int BaseAttr_offsets_[8] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BaseAttr, part_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BaseAttr, level_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BaseAttr, quality_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BaseAttr, quarank_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BaseAttr, hp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BaseAttr, defence_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BaseAttr, atk_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BaseAttr, atk_speed_),
  };
  BaseAttr_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      BaseAttr_descriptor_,
      BaseAttr::default_instance_,
      BaseAttr_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BaseAttr, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BaseAttr, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(BaseAttr));
  BaseAttr_ePart_descriptor_ = BaseAttr_descriptor_->enum_type(0);
  BaseAttr_eQuality_descriptor_ = BaseAttr_descriptor_->enum_type(1);
  BaseAttr_eQualityRank_descriptor_ = BaseAttr_descriptor_->enum_type(2);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_BaseAttr_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    BaseAttr_descriptor_, &BaseAttr::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_BaseAttr_2eproto() {
  delete BaseAttr::default_instance_;
  delete BaseAttr_reflection_;
}

void protobuf_AddDesc_BaseAttr_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016BaseAttr.proto\"\273\004\n\010BaseAttr\022)\n\004part\030\001 "
    "\002(\0162\017.BaseAttr.ePart:\nkPart_Null\022\020\n\005leve"
    "l\030\002 \002(\005:\0011\0223\n\007quality\030\003 \002(\0162\022.BaseAttr.e"
    "Quality:\016kQuality_White\0223\n\007quaRank\030\004 \002(\016"
    "2\026.BaseAttr.eQualityRank:\nkQuaRank_0\022\n\n\002"
    "hp\030\005 \001(\005\022\017\n\007defence\030\006 \001(\005\022\013\n\003atk\030\007 \001(\005\022\021"
    "\n\tatk_speed\030\010 \001(\005\"a\n\005ePart\022\016\n\nkPart_Null"
    "\020\000\022\021\n\rkPart_Fighter\020\001\022\017\n\013kPart_Armor\020\002\022\021"
    "\n\rkPart_Wingman\020\003\022\021\n\rkPart_Attache\020\004\"\202\001\n"
    "\010eQuality\022\021\n\rkQuality_Gray\020\000\022\022\n\016kQuality"
    "_White\020\001\022\022\n\016kQuality_Green\020\002\022\021\n\rkQuality"
    "_Blue\020\003\022\023\n\017kQuality_Purple\020\004\022\023\n\017kQuality"
    "_Orange\020\005\"c\n\014eQualityRank\022\016\n\nkQuaRank_0\020"
    "\000\022\016\n\nkQuaRank_1\020\001\022\016\n\nkQuaRank_2\020\002\022\020\n\014kQu"
    "aRank_Max\020\003\022\021\n\rkQuaRank_Gold\020\004", 590);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "BaseAttr.proto", &protobuf_RegisterTypes);
  BaseAttr::default_instance_ = new BaseAttr();
  BaseAttr::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_BaseAttr_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_BaseAttr_2eproto {
  StaticDescriptorInitializer_BaseAttr_2eproto() {
    protobuf_AddDesc_BaseAttr_2eproto();
  }
} static_descriptor_initializer_BaseAttr_2eproto_;

// ===================================================================

const ::google::protobuf::EnumDescriptor* BaseAttr_ePart_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return BaseAttr_ePart_descriptor_;
}
bool BaseAttr_ePart_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const BaseAttr_ePart BaseAttr::kPart_Null;
const BaseAttr_ePart BaseAttr::kPart_Fighter;
const BaseAttr_ePart BaseAttr::kPart_Armor;
const BaseAttr_ePart BaseAttr::kPart_Wingman;
const BaseAttr_ePart BaseAttr::kPart_Attache;
const BaseAttr_ePart BaseAttr::ePart_MIN;
const BaseAttr_ePart BaseAttr::ePart_MAX;
const int BaseAttr::ePart_ARRAYSIZE;
#endif  // _MSC_VER
const ::google::protobuf::EnumDescriptor* BaseAttr_eQuality_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return BaseAttr_eQuality_descriptor_;
}
bool BaseAttr_eQuality_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const BaseAttr_eQuality BaseAttr::kQuality_Gray;
const BaseAttr_eQuality BaseAttr::kQuality_White;
const BaseAttr_eQuality BaseAttr::kQuality_Green;
const BaseAttr_eQuality BaseAttr::kQuality_Blue;
const BaseAttr_eQuality BaseAttr::kQuality_Purple;
const BaseAttr_eQuality BaseAttr::kQuality_Orange;
const BaseAttr_eQuality BaseAttr::eQuality_MIN;
const BaseAttr_eQuality BaseAttr::eQuality_MAX;
const int BaseAttr::eQuality_ARRAYSIZE;
#endif  // _MSC_VER
const ::google::protobuf::EnumDescriptor* BaseAttr_eQualityRank_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return BaseAttr_eQualityRank_descriptor_;
}
bool BaseAttr_eQualityRank_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const BaseAttr_eQualityRank BaseAttr::kQuaRank_0;
const BaseAttr_eQualityRank BaseAttr::kQuaRank_1;
const BaseAttr_eQualityRank BaseAttr::kQuaRank_2;
const BaseAttr_eQualityRank BaseAttr::kQuaRank_Max;
const BaseAttr_eQualityRank BaseAttr::kQuaRank_Gold;
const BaseAttr_eQualityRank BaseAttr::eQualityRank_MIN;
const BaseAttr_eQualityRank BaseAttr::eQualityRank_MAX;
const int BaseAttr::eQualityRank_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int BaseAttr::kPartFieldNumber;
const int BaseAttr::kLevelFieldNumber;
const int BaseAttr::kQualityFieldNumber;
const int BaseAttr::kQuaRankFieldNumber;
const int BaseAttr::kHpFieldNumber;
const int BaseAttr::kDefenceFieldNumber;
const int BaseAttr::kAtkFieldNumber;
const int BaseAttr::kAtkSpeedFieldNumber;
#endif  // !_MSC_VER

BaseAttr::BaseAttr()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void BaseAttr::InitAsDefaultInstance() {
}

BaseAttr::BaseAttr(const BaseAttr& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void BaseAttr::SharedCtor() {
  _cached_size_ = 0;
  part_ = 0;
  level_ = 1;
  quality_ = 1;
  quarank_ = 0;
  hp_ = 0;
  defence_ = 0;
  atk_ = 0;
  atk_speed_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

BaseAttr::~BaseAttr() {
  SharedDtor();
}

void BaseAttr::SharedDtor() {
  if (this != default_instance_) {
  }
}

void BaseAttr::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* BaseAttr::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return BaseAttr_descriptor_;
}

const BaseAttr& BaseAttr::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_BaseAttr_2eproto();
  return *default_instance_;
}

BaseAttr* BaseAttr::default_instance_ = NULL;

BaseAttr* BaseAttr::New() const {
  return new BaseAttr;
}

void BaseAttr::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    part_ = 0;
    level_ = 1;
    quality_ = 1;
    quarank_ = 0;
    hp_ = 0;
    defence_ = 0;
    atk_ = 0;
    atk_speed_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool BaseAttr::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .BaseAttr.ePart part = 1 [default = kPart_Null];
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::BaseAttr_ePart_IsValid(value)) {
            set_part(static_cast< ::BaseAttr_ePart >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_level;
        break;
      }

      // required int32 level = 2 [default = 1];
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_level:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &level_)));
          set_has_level();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_quality;
        break;
      }

      // required .BaseAttr.eQuality quality = 3 [default = kQuality_White];
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_quality:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::BaseAttr_eQuality_IsValid(value)) {
            set_quality(static_cast< ::BaseAttr_eQuality >(value));
          } else {
            mutable_unknown_fields()->AddVarint(3, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_quaRank;
        break;
      }

      // required .BaseAttr.eQualityRank quaRank = 4 [default = kQuaRank_0];
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_quaRank:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::BaseAttr_eQualityRank_IsValid(value)) {
            set_quarank(static_cast< ::BaseAttr_eQualityRank >(value));
          } else {
            mutable_unknown_fields()->AddVarint(4, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_hp;
        break;
      }

      // optional int32 hp = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_hp:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &hp_)));
          set_has_hp();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(48)) goto parse_defence;
        break;
      }

      // optional int32 defence = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_defence:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &defence_)));
          set_has_defence();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(56)) goto parse_atk;
        break;
      }

      // optional int32 atk = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_atk:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &atk_)));
          set_has_atk();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(64)) goto parse_atk_speed;
        break;
      }

      // optional int32 atk_speed = 8;
      case 8: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_atk_speed:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &atk_speed_)));
          set_has_atk_speed();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void BaseAttr::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required .BaseAttr.ePart part = 1 [default = kPart_Null];
  if (has_part()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->part(), output);
  }

  // required int32 level = 2 [default = 1];
  if (has_level()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->level(), output);
  }

  // required .BaseAttr.eQuality quality = 3 [default = kQuality_White];
  if (has_quality()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      3, this->quality(), output);
  }

  // required .BaseAttr.eQualityRank quaRank = 4 [default = kQuaRank_0];
  if (has_quarank()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      4, this->quarank(), output);
  }

  // optional int32 hp = 5;
  if (has_hp()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->hp(), output);
  }

  // optional int32 defence = 6;
  if (has_defence()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(6, this->defence(), output);
  }

  // optional int32 atk = 7;
  if (has_atk()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(7, this->atk(), output);
  }

  // optional int32 atk_speed = 8;
  if (has_atk_speed()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(8, this->atk_speed(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* BaseAttr::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required .BaseAttr.ePart part = 1 [default = kPart_Null];
  if (has_part()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->part(), target);
  }

  // required int32 level = 2 [default = 1];
  if (has_level()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->level(), target);
  }

  // required .BaseAttr.eQuality quality = 3 [default = kQuality_White];
  if (has_quality()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      3, this->quality(), target);
  }

  // required .BaseAttr.eQualityRank quaRank = 4 [default = kQuaRank_0];
  if (has_quarank()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      4, this->quarank(), target);
  }

  // optional int32 hp = 5;
  if (has_hp()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->hp(), target);
  }

  // optional int32 defence = 6;
  if (has_defence()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, this->defence(), target);
  }

  // optional int32 atk = 7;
  if (has_atk()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, this->atk(), target);
  }

  // optional int32 atk_speed = 8;
  if (has_atk_speed()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(8, this->atk_speed(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int BaseAttr::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .BaseAttr.ePart part = 1 [default = kPart_Null];
    if (has_part()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->part());
    }

    // required int32 level = 2 [default = 1];
    if (has_level()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->level());
    }

    // required .BaseAttr.eQuality quality = 3 [default = kQuality_White];
    if (has_quality()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->quality());
    }

    // required .BaseAttr.eQualityRank quaRank = 4 [default = kQuaRank_0];
    if (has_quarank()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->quarank());
    }

    // optional int32 hp = 5;
    if (has_hp()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->hp());
    }

    // optional int32 defence = 6;
    if (has_defence()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->defence());
    }

    // optional int32 atk = 7;
    if (has_atk()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->atk());
    }

    // optional int32 atk_speed = 8;
    if (has_atk_speed()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->atk_speed());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void BaseAttr::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const BaseAttr* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const BaseAttr*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void BaseAttr::MergeFrom(const BaseAttr& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_part()) {
      set_part(from.part());
    }
    if (from.has_level()) {
      set_level(from.level());
    }
    if (from.has_quality()) {
      set_quality(from.quality());
    }
    if (from.has_quarank()) {
      set_quarank(from.quarank());
    }
    if (from.has_hp()) {
      set_hp(from.hp());
    }
    if (from.has_defence()) {
      set_defence(from.defence());
    }
    if (from.has_atk()) {
      set_atk(from.atk());
    }
    if (from.has_atk_speed()) {
      set_atk_speed(from.atk_speed());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void BaseAttr::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BaseAttr::CopyFrom(const BaseAttr& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BaseAttr::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000000f) != 0x0000000f) return false;

  return true;
}

void BaseAttr::Swap(BaseAttr* other) {
  if (other != this) {
    std::swap(part_, other->part_);
    std::swap(level_, other->level_);
    std::swap(quality_, other->quality_);
    std::swap(quarank_, other->quarank_);
    std::swap(hp_, other->hp_);
    std::swap(defence_, other->defence_);
    std::swap(atk_, other->atk_);
    std::swap(atk_speed_, other->atk_speed_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata BaseAttr::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = BaseAttr_descriptor_;
  metadata.reflection = BaseAttr_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
