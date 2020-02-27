#include "ResourceHolder.h"

template <typename Identifier, typename Resource>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename)
{
	std::unique_ptr<Resource> resource(new Resource());
	
	if(!resource -> loadFromFile(filename))
	{
		throw std::runtime_error("ResourceHolder::load - Failed to load "+filename);
	}
	
	auto inserted = mResourceMap.insert(std::make_pair(id, std::move(texture))); 
	assert(inserted.second); 
}

template <typename Identifier, typename Resource>
Resource& ResourceHolder<Resource, Identifier>::get(Resource id)
{
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());

    return *found->second; 
}

