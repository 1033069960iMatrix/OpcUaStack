/*
    DataTypeClass: EUInformation

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/EUInformation.h"

namespace OpcUaStackCore
{
    
    EUInformation::EUInformation(void)
    : Object()
    , ExtensionObjectBase()
    , namespaceUri_()
    , unitId_()
    , displayName_()
    , description_()
    {
    }
    
    EUInformation::~EUInformation(void)
    {
    }
    
    OpcUaString&
    EUInformation::namespaceUri(void)
    {
        return namespaceUri_;
    }
    
    OpcUaInt32&
    EUInformation::unitId(void)
    {
        return unitId_;
    }
    
    OpcUaLocalizedText&
    EUInformation::displayName(void)
    {
        return displayName_;
    }
    
    OpcUaLocalizedText&
    EUInformation::description(void)
    {
        return description_;
    }
    
    bool
    EUInformation::operator==(const EUInformation& value)
    {
        EUInformation* dst = const_cast<EUInformation*>(&value);
        if (namespaceUri_ != dst->namespaceUri()) return false;
        if (unitId_ != dst->unitId()) return false;
        if (displayName_ != dst->displayName()) return false;
        if (description_ != dst->description()) return false;
        return true;
    }
    
    bool
    EUInformation::operator!=(const EUInformation& value)
    {
        return !this->operator==(value);
    }
    
    void
    EUInformation::copyTo(EUInformation& value)
    {
        namespaceUri_.copyTo(value.namespaceUri());
        value.unitId_ = unitId_;
        displayName_.copyTo(value.displayName());
        description_.copyTo(value.description());
    }
    
    EUInformation&
    EUInformation::operator=(const EUInformation& value)
    {
        const_cast<EUInformation*>(&value)->copyTo(*this);
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
    EUInformation::factory(void)
    {
    	return constructSPtr<EUInformation>();
    }
    
    std::string
    EUInformation::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    EUInformation::typeName(void)
    {
    	return "EUInformation";
    }
    
    OpcUaNodeId
    EUInformation::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)887,0);
    }
    
    OpcUaNodeId
    EUInformation::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)889, 0);
    }
    
    OpcUaNodeId
    EUInformation::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)888, 0);
    }
    
    OpcUaNodeId
    EUInformation::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15376, 0);
    }
    
    void
    EUInformation::opcUaBinaryEncode(std::ostream& os) const
    {
        namespaceUri_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,unitId_);
        displayName_.opcUaBinaryEncode(os);
        description_.opcUaBinaryEncode(os);
    }
    
    void
    EUInformation::opcUaBinaryDecode(std::istream& is)
    {
        namespaceUri_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,unitId_);
        displayName_.opcUaBinaryDecode(is);
        description_.opcUaBinaryDecode(is);
    }
    
    bool
    EUInformation::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    EUInformation::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    EUInformation::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    EUInformation::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!namespaceUri_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("NamespaceUri", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, unitId_)) return false;
        pt.push_back(std::make_pair("UnitId", elementTree));
    
        elementTree.clear();
        if (!displayName_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("DisplayName", elementTree));
    
        elementTree.clear();
        if (!description_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Description", elementTree));
    
        return true;
    }
    
    bool
    EUInformation::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    EUInformation::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("NamespaceUri");
        if (!tree) return false;
        if (!namespaceUri_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("UnitId");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, unitId_)) return false;
    
        tree = pt.get_child_optional("DisplayName");
        if (!tree) return false;
        if (!displayName_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("Description");
        if (!tree) return false;
        if (!description_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    EUInformation::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    EUInformation::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    EUInformation::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    EUInformation::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    EUInformation::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	EUInformation* dst = dynamic_cast<EUInformation*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    EUInformation::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	EUInformation* dst = dynamic_cast<EUInformation*>(&extensionObjectBase);
    	return *const_cast<EUInformation*>(this) == *dst;
    }
    
    void
    EUInformation::out(std::ostream& os)
    {
        os << "NamespaceUri="; namespaceUri_.out(os);
        os << ", UnitId=" << unitId_;
        os << ", DisplayName="; displayName_.out(os);
        os << ", Description="; description_.out(os);
    }

}
