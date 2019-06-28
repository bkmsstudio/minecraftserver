#pragma once
#include SAMPEDGENGINE_PCH



// Other headers:
#include <SAMP-EDGEngine/Core/TypesAndDefinitions.hpp>

namespace samp_edgengine
{

/// <summary>
/// A building (or other map object) removed from the default map.
/// </summary>
struct RemovedBuilding
{
	constexpr static Int32 AnyModel = -1;
	
	/// <summary>
	/// Determines whether this instance is equal to the other instance.
	/// </summary>
	/// <param name="other_">The other removed building setup.</param>
	/// <returns>
	///		<c>true</c> if removed buildings are same; otherwise, <c>false</c>.
	/// </returns>
	constexpr bool operator==(RemovedBuilding const &other_) const
	{
		return model == other_.model && origin == other_.origin && radius == other_.radius;
	}
	
	/// <summary>
	/// Initializes a new instance of the <see cref="RemovedBuilding"/> struct.
	/// </summary>
	RemovedBuilding()
		: model{ -1 }
	{
	}

	Int32			model;		// What model should be removed?
	math::Vector3f	origin;		// From where the object should be removed?
	math::Meters	radius;		// In what radius the object should be removed?
};

} // namespace agdk.
