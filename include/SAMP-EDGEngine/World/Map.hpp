#pragma once
#include SAMPEDGENGINE_PCH



#include <SAMP-EDGEngine/World/Vehicle.hpp>
#include <SAMP-EDGEngine/World/Scene.hpp>
#include <SAMP-EDGEngine/World/RemovedBuilding.hpp>
#include <SAMP-EDGEngine/World/GangZone.hpp>
#include <SAMP-EDGEngine/World/Checkpoint.hpp>
#include <SAMP-EDGEngine/World/RaceCheckpoint.hpp>

#include <SAMP-EDGEngine/Core/Pointers.hpp>
#include <SAMP-EDGEngine/Core/Events.hpp>


namespace samp_edgengine
{

/// <summary>
/// 
/// </summary>
class MapClass
	:
	public IEventReceiver
{
public:
	template <typename TType>
	using ActorPtrType			= SharedPtr<TType>;
	template <typename TType>
	using ActorContainerType	= std::vector< ActorPtrType<TType> >;
	
	/// <summary>
	/// Initializes a new instance of the <see cref="MapClass"/> class.
	/// </summary>
	MapClass();

	/// <summary>
	/// Constructs specified thing on the map (either vehicle, static vehicle or scene).
	/// </summary>
	/// <param name="args_">The construction params.</param>
	/// <returns>Reference to the constructed thing.</returns>
	template <typename TType, typename... TArgTypes>
	TType& construct(TArgTypes&&...args_)
	{
		return this->finalizeConstruction( this->beginConstruction<TType>( std::forward<TArgTypes>( args_)... ) );
	}

	/// <summary>
	/// Begins construction of the specified thing (either vehicle, static vehicle or scene; it is not added yet to the map).
	/// </summary>
	/// <param name="args_">The construction params.</param>
	/// <returns>The only owning pointer to the constructed thing.</returns>
	template <typename TType, typename... TArgTypes>
	ActorPtrType<TType> beginConstruction(TArgTypes&&...args_)
	{
		return std::make_shared<TType>( std::forward<TArgTypes>( args_)... );
	}

	/// <summary>
	/// Finalizes the vehicle construction - adds it to the pool.
	/// </summary>
	/// <param name="vehicle_">The vehicle.</param>
	/// <returns>Reference to created vehicle.</returns>
	Vehicle& finalizeConstruction(ActorPtrType< Vehicle > const& vehicle_);

	/// <summary>
	/// Finalizes the static vehicle construction - adds it to the pool.
	/// </summary>
	/// <param name="vehicle_">The vehicle.</param>
	/// <returns>Reference to created static vehicle.</returns>
	StaticVehicle& finalizeConstruction(ActorPtrType< StaticVehicle > const& staticVehicle_);

	/// <summary>
	/// Finalizes the scene construction - adds it to the pool.
	/// </summary>
	/// <param name="scene_">The scene.</param>
	/// <returns>Reference to created scene vehicle.</returns>
	Scene& finalizeConstruction(ActorPtrType< Scene > const& scene_);

	/// <summary>
	/// Finalizes the gang zone construction - adds it to the pool.
	/// </summary>
	/// <param name="gangZone_">The gang zone.</param>
	/// <returns>Reference to created gang zone.</returns>
	GangZone& finalizeConstruction(ActorPtrType< GangZone > const& gangZone_);

	/// <summary>
	/// Finalizes the checkpoint construction - adds it to the pool.
	/// </summary>
	/// <param name="checkpoint_">The checkpoint.</param>
	/// <returns>Reference to created checkpoint.</returns>
	Checkpoint& finalizeConstruction(ActorPtrType< Checkpoint > const& checkpoint_);

	/// <summary>
	/// Finalizes the race checkpoint construction - adds it to the pool.
	/// </summary>
	/// <param name="raceCheckpoint_">The race checkpoint.</param>
	/// <returns>Reference to created race checkpoint.</returns>
	RaceCheckpoint& finalizeConstruction(ActorPtrType< RaceCheckpoint > const& raceCheckpoint_);

	/// <summary>
	/// Removes the specified vehicle.
	/// </summary>
	/// <param name="vehicle_">The vehicle.</param>
	/// <returns>
	///		<c>true</c> if vehicle existed and was removed; otherwise, <c>false</c>.
	/// </returns>
	bool remove(Vehicle & vehicle_);

	/// <summary>
	/// Removes the specified static vehicle.
	/// </summary>
	/// <param name="vehicle_">The static vehicle.</param>
	/// <returns>
	///		<c>true</c> if static vehicle existed and was removed; otherwise, <c>false</c>.
	/// </returns>
	bool remove(StaticVehicle & vehicle_);

	/// <summary>
	/// Removes the specified gang zone.
	/// </summary>
	/// <param name="gangZone_">The gang zone.</param>
	/// <returns>
	///		<c>true</c> if gang zone existed and was removed; otherwise, <c>false</c>.
	/// </returns>
	bool remove(GangZone const & gangZone_);
	
	/// <summary>
	/// Removes the specified checkpoint.
	/// </summary>
	/// <param name="checkpoint_">The checkpoint.</param>
	/// <returns>
	///		<c>true</c> if checkpoint existed and was removed; otherwise, <c>false</c>.
	/// </returns>
	bool remove(Checkpoint const &checkpoint_);
	
	/// <summary>
	/// Removes the specified race checkpoint.
	/// </summary>
	/// <param name="raceCheckpoint_">The race checkpoint.</param>
	/// <returns>
	///		<c>true</c> if race checkpoint existed and was removed; otherwise, <c>false</c>.
	/// </returns>
	bool remove(RaceCheckpoint const &raceCheckpoint_);

	/// <summary>
	/// Finds the vehicle using SAMP handle.
	/// </summary>
	/// <param name="handle_">The handle.</param>
	/// <returns>Pointer to found vehicle or nullptr if vehicle with this handle does not exist.</returns>
	Vehicle* findVehicleByHandle(Int32 const vehicleHandle_);
		
	/// <summary>
	/// Removes specified building (an original map object).
	/// </summary>
	/// <param name="removedBuilding_">The removed building.</param>
	void removeBuilding(RemovedBuilding const & removedBuilding_);

	/// <summary>
	/// Returns cref to vehicle pool.
	/// </summary>
	/// <returns>cref to vehicle pool.</returns>
	auto const& getVehicles() const {
		return m_vehicles;
	}

	/// <summary>
	/// Returns ref to vehicle pool.
	/// </summary>
	/// <returns>ref to vehicle pool.</returns>
	auto & getVehicles() {
		return m_vehicles;
	}

	/// <summary>
	/// Returns ref to static vehicle pool.
	/// </summary>
	/// <returns>ref to static vehicle pool.</returns>
	auto & getStaticVehicles() {
		return m_staticVehicles;
	}
	
	/// <summary>
	/// Returns cref to static vehicle pool.
	/// </summary>
	/// <returns>cref to static vehicle pool.</returns>
	auto const& getStaticVehicles() const {
		return m_staticVehicles;
	}
	
	/// <summary>
	/// Returns cref to scene pool.
	/// </summary>
	/// <returns>cref to scene pool.</returns>
	auto const& getScenes() const {
		return m_scenes;
	}

private:	
	
	/// <summary>
	/// Whens the player connects.
	/// </summary>
	/// <param name="player_">The player.</param>
	void whenPlayerConnects(Player & player_);

	/// <summary>
	/// Applies the removed building to the player.
	/// </summary>
	/// <param name="player_">The player.</param>
	/// <param name="building_">The building.</param>
	void applyRemovedBuilding(Player& player_, RemovedBuilding const& building_);

	/// <summary>
	/// Removes buildings for specified player.
	/// </summary>
	/// <param name="player_">The player.</param>
	void applyRemovedBuildings(Player & player_);

	ActorContainerType< Vehicle >			m_vehicles;
	ActorContainerType< StaticVehicle >		m_staticVehicles;
	ActorContainerType< Scene >				m_scenes;
	ActorContainerType< GangZone >			m_gangZones;
	ActorContainerType< Checkpoint >		m_checkpoints;
	ActorContainerType< RaceCheckpoint >	m_raceCheckpoints;

	std::vector< RemovedBuilding >			m_removedBuildings;
};

}
