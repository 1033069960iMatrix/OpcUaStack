/*
    EnumTypeClass: OpenFileMode

    Generated Source Code - please do not change this source code

    EnumTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
    BuildDate: 2018-Oct-28 13:35:47.167390
*/

#ifndef __OpcUaStackCore_OpenFileMode_h__
#define __OpcUaStackCore_OpenFileMode_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/XmlNumber.h"

namespace OpcUaStackCore
{
    
    class OpenFileMode
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<OpenFileMode> SPtr;
    
        typedef enum {
            EnumRead = 1,
            EnumWrite = 2,
            EnumEraseExisting = 4,
            EnumAppend = 8,
        } Enum;
    
        OpenFileMode(void);
        OpenFileMode(Enum enumeration);
        OpenFileMode(OpenFileMode& value);
        virtual ~OpenFileMode(void);
        
        int32_t& value(void);
        void enumeration(Enum enumeration);
        Enum enumeration(void);
        Enum str2Enum(const std::string& enumerationString);
        std::string enum2Str(Enum enumeration);
        std::string enum2Str(void);
        std::string toString(void);
        bool exist(const std::string& enumerationString);
        bool exist(Enum enumeration);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void);
        virtual OpcUaNodeId binaryTypeId(void);
        virtual OpcUaNodeId xmlTypeId(void);
        virtual void opcUaBinaryEncode(std::ostream& os) const;
        virtual void opcUaBinaryDecode(std::istream& is);
        virtual bool encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const;
        virtual bool decode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        void copyTo(OpenFileMode& value);
        bool operator==(const OpenFileMode& value) const;
        bool operator!=(const OpenFileMode& value) const;
        OpenFileMode& operator=(const OpenFileMode& value);
        OpenFileMode& operator=(const Enum& value);
    
      private:
        int32_t value_;
    
    };

}

#endif
