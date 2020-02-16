
#include <boost/serialization/access.hpp>
#include <boost/serialization/base_object.hpp> 
#include <boost/serialization/optional.hpp> 
#include <boost/serialization/map.hpp> 
#include <boost/serialization/shared_ptr.hpp>

namespace A
{
    typedef std::map<std::string, std::string> parameter_strings;
    struct Name
    {
        std::string firstname;
        std::string lastname;

        template<class Archive>
            void serialize(Archive &ar, const unsigned int version)
            {
                ar & firstname;
                ar & lastname;
            } 
    };

    struct Address
    {
        std::string street;
        std::string city;

        template<class Archive>
            void serialize(Archive &ar, const unsigned int version)
            {
                ar & street;
                ar & city;
            } 

    };

    struct FullData 
    {
        FullData();
        FullData(const parameter_strings & parms);

        virtual ~FullData();

        boost::optional<Name> nameinfo;       // instance of struct Name
        boost::optional<Address> addressinfo; // instance of struct Address
        parameter_strings detail;

        std::string country;
        int pincode;

        private :
        friend class boost::serialization::access;
        template<class Archive>
            void serialize(Archive &ar, const unsigned int version)
            {
                ar & nameinfo;       // are these enough to take of serialization of Name and 
                ar & addressinfo;   // Address
                ar & country;
                ar & pincode;
                ar & detail;
            } 
    };

}
