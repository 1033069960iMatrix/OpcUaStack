/*
    DataTypeClass: DataChangeFilter

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DataChangeFilter.h"

namespace OpcUaStackCore
{
    
    DataChangeFilter::DataChangeFilter(void)
    : MonitoringFilter()
    , trigger_()
    , deadbandType_()
    , deadbandValue_()
    {
    }
    
    DataChangeFilter::~DataChangeFilter(void)
    {
    }
    
    DataChangeTrigger&
    DataChangeFilter::trigger(void)
    {
        return trigger_;
    }
    
    OpcUaUInt32&
    DataChangeFilter::deadbandType(void)
    {
        return deadbandType_;
    }
    
    OpcUaDouble&
    DataChangeFilter::deadbandValue(void)
    {
        return deadbandValue_;
    }
    
    bool
    DataChangeFilter::operator==(const DataChangeFilter& value)
    {
        DataChangeFilter* dst = const_cast<DataChangeFilter*>(&value);
        if (trigger_ != dst->trigger()) return false;
        if (deadbandType_ != dst->deadbandType()) return false;
        if (deadbandValue_ != dst->deadbandValue()) return false;
        return true;
    }
    
    bool
    DataChangeFilter::operator!=(const DataChangeFilter& value)
    {
        return !this->operator==(value);
    }
    
    void
    DataChangeFilter::copyTo(DataChangeFilter& value)
    {
        trigger_.copyTo(value.trigger());
        value.deadbandType_ = deadbandType_;
        value.deadbandValue_ = deadbandValue_;
    }
    
    DataChangeFilter&
    DataChangeFilter::operator=(const DataChangeFilter& value)
    {
        const_cast<DataChangeFilter*>(&value)->copyTo(*this);
        return *this;
    }
    
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // ExtensionObjectBase
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    
    ExtensionObjectBase::SPtr
    DataChangeFilter::factory(void)
    {
    	return constructSPtr<DataChangeFilter>();
    }
    
    std::string
    DataChangeFilter::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DataChangeFilter::typeName(void)
    {
    	return "DataChangeFilter";
    }
    
    OpcUaNodeId
    DataChangeFilter::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)722,0);
    }
    
    OpcUaNodeId
    DataChangeFilter::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)724, 0);
    }
    
    OpcUaNodeId
    DataChangeFilter::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)723, 0);
    }
    
    OpcUaNodeId
    DataChangeFilter::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15294, 0);
    }
    
    void
    DataChangeFilter::opcUaBinaryEncode(std::ostream& os) const
    {
        MonitoringFilter::opcUaBinaryEncode(os);
        trigger_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,deadbandType_);
        OpcUaNumber::opcUaBinaryEncode(os,deadbandValue_);
    }
    
    void
    DataChangeFilter::opcUaBinaryDecode(std::istream& is)
    {
        MonitoringFilter::opcUaBinaryDecode(is);
        trigger_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,deadbandType_);
        OpcUaNumber::opcUaBinaryDecode(is,deadbandValue_);
    }
    
    bool
    DataChangeFilter::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    DataChangeFilter::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    DataChangeFilter::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DataChangeFilter::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!trigger_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Trigger", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, deadbandType_)) return false;
        pt.push_back(std::make_pair("DeadbandType", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, deadbandValue_)) return false;
        pt.push_back(std::make_pair("DeadbandValue", elementTree));
    
        return true;
    }
    
    bool
    DataChangeFilter::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataChangeFilter decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DataChangeFilter::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Trigger");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataChangeFilter decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!trigger_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DataChangeFilter decode xml error - decode failed")
                .parameter("Element", "Trigger");
            return false;
        }
    
        elementName = xmlns.addPrefix("DeadbandType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataChangeFilter decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, deadbandType_)) {
            Log(Error, "DataChangeFilter decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DeadbandValue");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataChangeFilter decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, deadbandValue_)) {
            Log(Error, "DataChangeFilter decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    DataChangeFilter::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    DataChangeFilter::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    DataChangeFilter::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    DataChangeFilter::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    DataChangeFilter::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DataChangeFilter* dst = dynamic_cast<DataChangeFilter*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DataChangeFilter::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DataChangeFilter* dst = dynamic_cast<DataChangeFilter*>(&extensionObjectBase);
    	return *const_cast<DataChangeFilter*>(this) == *dst;
    }
    
    void
    DataChangeFilter::out(std::ostream& os)
    {
        os << "Trigger="; trigger_.out(os);
        os << ", DeadbandType=" << deadbandType_;
        os << ", DeadbandValue=" << deadbandValue_;
    }

}
