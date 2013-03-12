//
// Generated file, do not edit! Created by opp_msgc 4.2 from SimplePacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "SimplePacket_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}



namespace omnetpptrafficgenerators {

Register_Class(SimplePacket);

SimplePacket::SimplePacket(const char *name, int kind) : cPacket(name,kind)
{
    this->DST_var = 0;
    this->SRC_var = 0;
    this->sessionId_var = 0;
    this->packetId_var = 0;
    this->priority_var = 0;
    this->payload_var = 0;
}

SimplePacket::SimplePacket(const SimplePacket& other) : cPacket(other)
{
    copy(other);
}

SimplePacket::~SimplePacket()
{
}

SimplePacket& SimplePacket::operator=(const SimplePacket& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void SimplePacket::copy(const SimplePacket& other)
{
    this->DST_var = other.DST_var;
    this->SRC_var = other.SRC_var;
    this->sessionId_var = other.sessionId_var;
    this->packetId_var = other.packetId_var;
    this->priority_var = other.priority_var;
    this->payload_var = other.payload_var;
}

void SimplePacket::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->DST_var);
    doPacking(b,this->SRC_var);
    doPacking(b,this->sessionId_var);
    doPacking(b,this->packetId_var);
    doPacking(b,this->priority_var);
    doPacking(b,this->payload_var);
}

void SimplePacket::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->DST_var);
    doUnpacking(b,this->SRC_var);
    doUnpacking(b,this->sessionId_var);
    doUnpacking(b,this->packetId_var);
    doUnpacking(b,this->priority_var);
    doUnpacking(b,this->payload_var);
}

int SimplePacket::getDST() const
{
    return DST_var;
}

void SimplePacket::setDST(int DST)
{
    this->DST_var = DST;
}

int SimplePacket::getSRC() const
{
    return SRC_var;
}

void SimplePacket::setSRC(int SRC)
{
    this->SRC_var = SRC;
}

int SimplePacket::getSessionId() const
{
    return sessionId_var;
}

void SimplePacket::setSessionId(int sessionId)
{
    this->sessionId_var = sessionId;
}

int SimplePacket::getPacketId() const
{
    return packetId_var;
}

void SimplePacket::setPacketId(int packetId)
{
    this->packetId_var = packetId;
}

int SimplePacket::getPriority() const
{
    return priority_var;
}

void SimplePacket::setPriority(int priority)
{
    this->priority_var = priority;
}

const char * SimplePacket::getPayload() const
{
    return payload_var.c_str();
}

void SimplePacket::setPayload(const char * payload)
{
    this->payload_var = payload;
}

class SimplePacketDescriptor : public cClassDescriptor
{
  public:
    SimplePacketDescriptor();
    virtual ~SimplePacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(SimplePacketDescriptor);

SimplePacketDescriptor::SimplePacketDescriptor() : cClassDescriptor("omnetpptrafficgenerators::SimplePacket", "cPacket")
{
}

SimplePacketDescriptor::~SimplePacketDescriptor()
{
}

bool SimplePacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SimplePacket *>(obj)!=NULL;
}

const char *SimplePacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SimplePacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int SimplePacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *SimplePacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "DST",
        "SRC",
        "sessionId",
        "packetId",
        "priority",
        "payload",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int SimplePacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='D' && strcmp(fieldName, "DST")==0) return base+0;
    if (fieldName[0]=='S' && strcmp(fieldName, "SRC")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sessionId")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetId")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "priority")==0) return base+4;
    if (fieldName[0]=='p' && strcmp(fieldName, "payload")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SimplePacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
        "string",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *SimplePacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int SimplePacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SimplePacket *pp = (SimplePacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SimplePacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SimplePacket *pp = (SimplePacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getDST());
        case 1: return long2string(pp->getSRC());
        case 2: return long2string(pp->getSessionId());
        case 3: return long2string(pp->getPacketId());
        case 4: return long2string(pp->getPriority());
        case 5: return oppstring2string(pp->getPayload());
        default: return "";
    }
}

bool SimplePacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SimplePacket *pp = (SimplePacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setDST(string2long(value)); return true;
        case 1: pp->setSRC(string2long(value)); return true;
        case 2: pp->setSessionId(string2long(value)); return true;
        case 3: pp->setPacketId(string2long(value)); return true;
        case 4: pp->setPriority(string2long(value)); return true;
        case 5: pp->setPayload((value)); return true;
        default: return false;
    }
}

const char *SimplePacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<6) ? fieldStructNames[field] : NULL;
}

void *SimplePacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SimplePacket *pp = (SimplePacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

}; // end namespace omnetpptrafficgenerators

