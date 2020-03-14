#include <boost/serialization/export.hpp>
#include "simpledata.h"
#include <iostream>
namespace A
{
    FullData::FullData()
    {

    }

    FullData::~FullData()
    {

    }

    FullData::FullData(const parameter_strings & parms): detail(parms)
    {

        // impelmentation
    }

}

#include <boost/archive/text_oarchive.hpp>

BOOST_CLASS_EXPORT_IMPLEMENT(A::FullData)
BOOST_CLASS_IMPLEMENTATION(A::FullData    , boost::serialization::object_serializable)
BOOST_CLASS_TRACKING(A::FullData          , boost::serialization::track_never)

int main()
{
    A::FullData data({ { "key1", "value1" }, { "key2" , "value2" } });
    data.nameinfo    = A::Name    { "firstname", "lastname" };
    data.addressinfo = A::Address { "street", "city" };
    data.pincode     = 99977;
    data.country     = "Gibraltar";

    boost::archive::text_oarchive oa(std::cout);
    oa << data;
}

