#include <string>
#include <map>

#include <SFML/Graphics.hpp>

#include "ResourcePath.hpp"

template <typename Resource, typename Identifier> 
class ResourceHolder
{
	public:
        void load(Identifier id, const std::string& filename);
        
        template <typename Parameter>
        void load(Identifier id, const std::string& filename, const Parameter& secondParam);
        
        Resource& get(Identifier id);
        const Resource& get(Identifier id) const;
        
	private:
		std::map<Identifier, std::unique_ptr<Resource> > mResourceMap;
};

namespace Textures
{
    enum ID { Landscape, Airplane, Missile, Eagle, Raptor, Desert, TitleScreen };
 
    typedef ResourceHolder<sf::Texture, ID> TextureHolder;
}

namespace Fonts
{
    enum ID
    {
        Main,
    };
    
    typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;
}

