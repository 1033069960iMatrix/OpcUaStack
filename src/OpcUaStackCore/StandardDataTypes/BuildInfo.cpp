/*
    DataTypeClass: BuildInfo

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/BuildInfo.h"

namespace OpcUaStackCore
{
    
    BuildInfo::BuildInfo(void)
    : Object()
    , ExtensionObjectBase()
    , productUri_()
    , manufacturerName_()
    , productName_()
    , softwareVersion_()
    , buildNumber_()
    , buildDate_()
    {
    }
    
    BuildInfo::~BuildInfo(void)
    {
    }
    
    OpcUaString&
    BuildInfo::productUri(void)
    {
        return productUri_;
    }
    
    OpcUaString&
    BuildInfo::manufacturerName(void)
    {
        return manufacturerName_;
    }
    
    OpcUaString&
    BuildInfo::productName(void)
    {
        return productName_;
    }
    
    OpcUaString&
    BuildInfo::softwareVersion(void)
    {
        return softwareVersion_;
    }
    
    OpcUaString&
    BuildInfo::buildNumber(void)
    {
        return buildNumber_;
    }
    
    OpcUaUtcTime&
    BuildInfo::buildDate(void)
    {
        return buildDate_;
    }
    
    bool
    BuildInfo::operator==(const BuildInfo& value) const
    {
        BuildInfo* dst = const_cast<BuildInfo*>(&value);
        if (productUri_ != dst->productUri()) return false;
        if (manufacturerName_ != dst->manufacturerName()) return false;
        if (productName_ != dst->productName()) return false;
        if (softwareVersion_ != dst->softwareVersion()) return false;
        if (buildNumber_ != dst->buildNumber()) return false;
        if (buildDate_ != dst->buildDate()) return false;
        return true;
    }
    
    bool
    BuildInfo::operator!=(const BuildInfo& value) const
    {
        return !this->operator==(value);
    }
    
    void
    BuildInfo::copyTo(BuildInfo& value)
    {
        value.productUri_ = productUri_;
        value.manufacturerName_ = manufacturerName_;
        value.productName_ = productName_;
        value.softwareVersion_ = softwareVersion_;
        value.buildNumber_ = buildNumber_;
        value.buildDate_ = buildDate_;
    }
    
    BuildInfo&
    BuildInfo::operator=(const BuildInfo& value)
    {
        const_cast<BuildInfo*>(&value)->copyTo(*this);
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
    BuildInfo::factory(void)
    {
    	return constructSPtr<BuildInfo>();
    }
    
    OpcUaNodeId
    BuildInfo::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    BuildInfo::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    void
    BuildInfo::opcUaBinaryEncode(std::ostream& os) const
    {
        productUri_.opcUaBinaryEncode(os);
        manufacturerName_.opcUaBinaryEncode(os);
        productName_.opcUaBinaryEncode(os);
        softwareVersion_.opcUaBinaryEncode(os);
        buildNumber_.opcUaBinaryEncode(os);
        buildDate_.opcUaBinaryEncode(os);
    }
    
    void
    BuildInfo::opcUaBinaryDecode(std::istream& is)
    {
        productUri_.opcUaBinaryDecode(is);
        manufacturerName_.opcUaBinaryDecode(is);
        productName_.opcUaBinaryDecode(is);
        softwareVersion_.opcUaBinaryDecode(is);
        buildNumber_.opcUaBinaryDecode(is);
        buildDate_.opcUaBinaryDecode(is);
    }
    
    bool
    BuildInfo::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    BuildInfo::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    BuildInfo::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    BuildInfo::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        if (!productUri_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ProductUri", elementTree));
    
        if (!manufacturerName_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ManufacturerName", elementTree));
    
        if (!productName_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ProductName", elementTree));
    
        if (!softwareVersion_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("SoftwareVersion", elementTree));
    
        if (!buildNumber_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("BuildNumber", elementTree));
    
        if (!buildDate_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("BuildDate", elementTree));
    
        return true;
    }
    
    bool
    BuildInfo::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    BuildInfo::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("ProductUri");
        if (!tree) return false;
        if (!productUri_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("ManufacturerName");
        if (!tree) return false;
        if (!manufacturerName_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("ProductName");
        if (!tree) return false;
        if (!productName_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("SoftwareVersion");
        if (!tree) return false;
        if (!softwareVersion_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("BuildNumber");
        if (!tree) return false;
        if (!buildNumber_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("BuildDate");
        if (!tree) return false;
        if (!buildDate_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    void
    BuildInfo::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	BuildInfo* dst = dynamic_cast<BuildInfo*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    BuildInfo::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	BuildInfo* dst = dynamic_cast<BuildInfo*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    BuildInfo::out(std::ostream& os)
    {
        os << "ProductUri="; productUri_.out(os);
        os << ", ManufacturerName="; manufacturerName_.out(os);
        os << ", ProductName="; productName_.out(os);
        os << ", SoftwareVersion="; softwareVersion_.out(os);
        os << ", BuildNumber="; buildNumber_.out(os);
        os << ", BuildDate="; buildDate_.out(os);
    }

}
