// File description:
// Includes the entire SAMP-EDGEngine.
#pragma once

#ifndef SAMPEDGENGINE_PCH
#define SAMPEDGENGINE_PCH <SAMP-EDGEngine/EnginePCH.hpp>
#endif
#include SAMPEDGENGINE_PCH

#include <SAMP-EDGEngine/Dependencies/SampGDK.hpp>
#include <SAMP-EDGEngine/Dependencies/QuickMaffs.hpp>

// Core/:
#include <SAMP-EDGEngine/Core/TaskSystem.hpp>
#include <SAMP-EDGEngine/Core/Events.hpp>
#include <SAMP-EDGEngine/Core/Clock.hpp>
#include <SAMP-EDGEngine/Core/Color.hpp>
#include <SAMP-EDGEngine/Core/Exceptions.hpp>
#include <SAMP-EDGEngine/Core/Pointers.hpp>
#include <SAMP-EDGEngine/Core/TypeTraits.hpp>
#include <SAMP-EDGEngine/Core/Log.hpp>


#include <SAMP-EDGEngine/Core/TextInc.hpp>
#include <SAMP-EDGEngine/Core/ContainerInc.hpp>
#include <SAMP-EDGEngine/Core/BasicInterfacesInc.hpp>


// World/:
#include <SAMP-EDGEngine/World/MapObject.hpp>
#include <SAMP-EDGEngine/World/Scene.hpp>
#include <SAMP-EDGEngine/World/Vehicle.hpp>
#include <SAMP-EDGEngine/World/Map.hpp>
#include <SAMP-EDGEngine/World/GangZone.hpp>
#include <SAMP-EDGEngine/World/Checkpoint.hpp>
#include <SAMP-EDGEngine/World/RaceCheckpoint.hpp>

// --> World/MapObject/:
#include <SAMP-EDGEngine/World/GlobalObject.hpp>
#include <SAMP-EDGEngine/World/PersonalObject.hpp>
#include <SAMP-EDGEngine/World/UniversalObject.hpp>

// --> World/Streamer/:
#include <SAMP-EDGEngine/World/Streamer/Chunk.hpp>
#include <SAMP-EDGEngine/World/Streamer/ChunkActor.hpp>
#include <SAMP-EDGEngine/World/Streamer/GlobalActorWrapper.hpp>
#include <SAMP-EDGEngine/World/Streamer/GlobalObjectWrapper.hpp>
#include <SAMP-EDGEngine/World/Streamer/VehicleWrapper.hpp>
#include <SAMP-EDGEngine/World/Streamer/PlayerWrapper.hpp>
#include <SAMP-EDGEngine/World/Streamer/StreamerSettings.hpp>
#include <SAMP-EDGEngine/World/Streamer/Streamer.hpp>

// Server/:
#include <SAMP-EDGEngine/Server/Chat.hpp>
#include <SAMP-EDGEngine/Server/GameMode.hpp>
#include <SAMP-EDGEngine/Server/GameModeChild.hpp>
#include <SAMP-EDGEngine/Server/Server.hpp>
#include <SAMP-EDGEngine/Server/TextDraw.hpp>
#include <SAMP-EDGEngine/Server/PlayerTextDraw.hpp>
#include <SAMP-EDGEngine/Server/GlobalTextDraw.hpp>
#include <SAMP-EDGEngine/Server/PlayerTextDrawPanel.hpp>
#include <SAMP-EDGEngine/Server/GlobalTextDrawPanel.hpp>

#include <SAMP-EDGEngine/Server/ServerDebugLog.hpp>


// --> Server/Command/:
#include <SAMP-EDGEngine/Server/Command.hpp>
#include <SAMP-EDGEngine/Server/CommandManager.hpp>

// --> Server/Player:
#include <SAMP-EDGEngine/Server/Player.hpp>
#include <SAMP-EDGEngine/Server/PlayerPool.hpp>
#include <SAMP-EDGEngine/Server/Weapon.hpp>
#include <SAMP-EDGEngine/Server/Teleport.hpp>

#include <SAMP-EDGEngine/Server/Dialog.hpp>

// TODO: sort and make sure everything is added here.
