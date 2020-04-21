#ifndef ResourceHolder_h
#define ResourceHolder_h

#include <string>
#include <map>

#include <SFML/Graphics.hpp>

#include "ResourcePath.hpp"

#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>


template <typename Resource, typename Identifier>
class ResourceHolder
{
    public:
        void                        load(Identifier id, const std::string& filename);

        template <typename Parameter>
        void                        load(Identifier id, const std::string& filename, const Parameter& secondParam);

        Resource&                    get(Identifier id);
        const Resource&                get(Identifier id) const;


    private:
        void                        insertResource(Identifier id, std::unique_ptr<Resource> resource);


    private:
        std::map<Identifier, std::unique_ptr<Resource>>    mResourceMap;
};


#endif
