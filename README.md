# GameDNDcpp

**DND_main:**
sets up a server to handle multiple clients concurrently using threads. The main() function initializes a Game instance and spawns multiple threads, each running the ServerPlay() function of the Game instance to handle client interactions.

**DND_staticLib:**
Game class:
The game initializes the networking subsystem (SimpleNetMT) and the dungeon (Dungeon_mt). It continuously waits for connections from clients, greets them, registers them as players in the dungeon, and executes game logic through a GameExecuter instance, which implements the state machine design pattern. The Play() function serves as the entry point for the game execution. It initializes input and output streams (cinReader and coutWriter) according to the Command design pattern and starts general gameplay.

```
├── DND_main  // DND_main folder: all code beside DND_MAIN_V02.cpp wrote by someone else
│   ├── header
│   │   ├── AsyncNetworkHandler.h
│   │   ├── BlockingQueueMT.h
│   │   ├── SimpleNetMT.h
│   │   └── UrlPathReader.h
│   └── source
│       ├── AsyncNetworkHandler .cpp
│       ├── DND_MAIN_V02.cpp
│       ├── SimpleNetMT.cpp
│       └── UrlPathReader.cpp
├── DND_staticLib
│   ├── header
│   │   ├── Action 
│   │   │   ├── Action.h
│   │   │   ├── ActionResponse.h
│   │   │   ├── Attack.h
│   │   │   ├── AttackDragon.h
│   │   │   ├── Left.h
│   │   │   ├── Look.h
│   │   │   ├── Right.h
│   │   │   ├── Shout.h
│   │   │   ├── StringActionResponse.h
│   │   │   ├── Take.h
│   │   │   ├── Talk.h
│   │   │   └── Walk.h
│   │   ├── Dungeon
│   │   │   ├── Dragon.h
│   │   │   ├── Dungeon.h
│   │   │   ├── Monster.h
│   │   │   ├── Room.h
│   │   │   └── Wall.h
│   │   ├── Game
│   │   │   ├── Game.h
│   │   │   ├── GameExecuter.h
│   │   │   ├── GameParams.h
│   │   │   ├── Player.h
│   │   │   ├── States
│   │   │   │   ├── State.h
│   │   │   │   ├── StateBase.h
│   │   │   │   └── StateInput.h
│   │   │   └── StatesActParams.h
│   │   ├── IO
│   │   │   ├── CinReader.h
│   │   │   ├── CoutWriter.h
│   │   │   ├── NetReader.h
│   │   │   ├── NetWriter.h
│   │   │   ├── Reader.h
│   │   │   ├── UserParser.h
│   │   │   ├── Writer.h
│   │   │   └── framework.h
│   │   └── Subject Observer
│   │       ├── ObserverBase.h
│   │       ├── ObserverPlayer.h
│   │       ├── SubjectBase.h
│   │       └── SubjectRoom.h
│   └── source
│       ├── Action  
│       │   ├── Action.cpp
│       │   ├── ActionResponse.cpp
│       │   ├── Attack.cpp
│       │   ├── AttackDragon.cpp
│       │   ├── Left.cpp
│       │   ├── Look.cpp
│       │   ├── Right.cpp
│       │   ├── Shout.cpp
│       │   ├── StringActionResponse.cpp
│       │   ├── Take.cpp
│       │   ├── Talk.cpp
│       │   └── Walk.cpp
│       ├── Dungeon
│       │   ├── Dragon.cpp
│       │   ├── Dungeon.cpp
│       │   ├── Monster.cpp
│       │   ├── Room.cpp
│       │   └── Wall.cpp
│       ├── Game
│       │   ├── Game.cpp
│       │   ├── GameExecuter.cpp
│       │   ├── GameParams.cpp
│       │   ├── Player.cpp
│       │   └── States
│       │       ├── State.cpp
│       │       ├── StateBase.cpp
│       │       └── StateInput.cpp
│       ├── IO
│       │   ├── CinReader.cpp
│       │   ├── CoutWriter.cpp
│       │   ├── NetReader.cpp
│       │   ├── NetWriter.cpp
│       │   ├── Reader.cpp
│       │   ├── UserParser.cpp
│       │   └── Writer.cpp
│       └── Subject Observer
│           ├── ObserverBase.cpp
│           ├── ObserverPlayer.cpp
│           ├── SubjectBase.cpp
│           └── SubjectRoom.cpp
│   ├── external_libs
│   │   ├── Internet
│   │   │   ├── ...
│   │   └── spdlog
│   │       ├── ...
```
# UML


<img width="785" alt="image" src="https://github.com/barrShahar/GameDNDcpp/assets/59974036/e68a4af4-48d5-417a-9ff3-48ec23970753">

<img width="786" alt="image" src="https://github.com/barrShahar/GameDNDcpp/assets/59974036/90db48ae-9f3b-4ed5-8c69-c88057524fca">

# Example

![1708369576001](https://github.com/barrShahar/GameDNDcpp/assets/59974036/9729f760-e8cf-4b64-9aac-9b3c02e55bfe)


