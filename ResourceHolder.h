namespace Textures
{
	enum ID { Landscape, Airplane, Missile };
}

template <typename Resource, typename Identifier> 
class ResourceHolder
{
	public:
		void load(Identifier id, const std::string& filename);
		Resource& get(Identifier id);
		const Resource& get(Identifier id) const;
		

	private:
		std::map<Identifier, std::unique_ptr<Resource> > mResourceMap;
};

