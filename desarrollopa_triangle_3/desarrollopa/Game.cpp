#include "Game.h"


using namespace std;
using namespace std::chrono;

void Game::Init() {

    menuScene = new Menu();
    menuScene->Init();

    winScene = new WinScene();
    winScene->Init();

    defeatScene = new DefeatScene();
    defeatScene->Init();

    gameScene = new levelScene();
    gameScene->Init();

    activeScene = menuScene;

    cout << "[GAME] Init..." << endl;
 

    // Configuramos el emisor
    int numParticulas = 1000;
    int tiempoEmision = 10;

    player1 = new Player();
    gameScene->AddGameObject(player1);


    ModelLoader* loader = new ModelLoader();
    loader->SetScale(0.8f);
    loader->LoadModel("..\\3dModels\\Spaceship4.obj");
    Model* playerModel = new Model();
    *playerModel = loader->GetModel();
    player1->SetModel3D(playerModel);
    playerModel->SetSpeed(Vector3D(0.0, 0.0, 0.0));
    playerModel->SetColor(Color(0.5f, 0.5f, 0.5f, 1.0f)); // Gris metálico

    for (int i = 1; i < 20; i++) {
        Battery* battery1 = new Battery();
        battery1->SetPosition(Vector3D(9.0 * 3 * i, (rand() % 12), 0.0));
        gameScene->AddGameObject(battery1);
        ModelLoader* loader6 = new ModelLoader();
        loader6->SetScale(1.0f);
        loader6->LoadModel("..\\3dModels\\Bolt.obj");
        Model* batteryModel = new Model();
        *batteryModel = loader6->GetModel();
        batteryModel->SetColor(Color(1.0f, 1.0f, 0.0f, 1.0f));
        battery1->SetModel3D(batteryModel);
        AddGameObject(battery1);
        delete loader6;
    }

    for (int i = 1; i < 30; i++) {
        Heart* heart1 = new Heart();
        heart1->SetPosition(Vector3D(9.0 * 2 * i, (rand() % 12), 0.0));
        gameScene->AddGameObject(heart1);
        ModelLoader* loader2 = new ModelLoader();
        loader2->SetScale(0.5f);
        loader2->LoadModel("..\\3dModels\\heart.obj");
        Model* heartModel = new Model();
        *heartModel = loader2->GetModel();
        heartModel->SetColor(Color(1.0, 0.0, 0.0, 1.0));
        heart1->SetModel3D(heartModel);
        AddGameObject(heart1);
        delete loader2;
    }

    for (int i = 1; i < 100; i++) {
        Meteorite* Meteorite1 = new Meteorite();
        Meteorite1->SetPosition(Vector3D(9.0 * i -2, (rand() % 12), 0.0));
        gameScene->AddGameObject(Meteorite1);
        ModelLoader* loader3 = new ModelLoader();
        loader3->SetScale(0.5f);
        loader3->LoadModel("..\\3dModels\\rock_001.obj");
        Model* meteoriteModel = new Model();
        *meteoriteModel = loader3->GetModel(); 
        meteoriteModel->SetColor(Color(0.3f, 0.3f, 0.3f, 1.0f)); // Gris oscuro
        Meteorite1->SetModel3D(meteoriteModel);
        AddGameObject(Meteorite1);
        delete loader3;
    }

    Star* star1 = new Star();
    ModelLoader* loader7 = new ModelLoader();
    loader7->SetScale(0.5f);
    loader7->LoadModel("..\\3dModels\\star.obj");
    Model* starModel = new Model();
    *starModel = loader7->GetModel();
    star1->SetModel3D(starModel);
    starModel->SetColor(Color(1.0f, 1.0f, 0.6f, 0.8f)); // Amarillo blanquecino


    EmmiterConfiguration Config(numParticulas, tiempoEmision, starModel);
    Emmiter* emisor = new Emmiter(Config);
    menuScene->AddGameObject(emisor);
    winScene->AddGameObject(emisor);
    defeatScene->AddGameObject(emisor);

    AddGameObject(player1);

    this->activeScene = menuScene;
    gameScene->SetPlayer(player1);
}

void Game::Render() {
    if (activeScene) {
        activeScene->Render();  // Renderiza la escena activa (ya sea el menú o la escena 2)
    }
}

void Game::Update(const float& time) {
    // Actualizar el tiempo
    milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

    if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdateTime > UPDATE_PERIOD) {
        if (activeScene) {
            activeScene->Update(TIME_INCREMENT);
        }
        this->lastUpdateTime = currentTime.count() - this->initialMilliseconds.count();
    }

    // Actualizar todos los objetos
    for (auto* object : gameObjects) {
        if (object && !object->IsMarkedForDeletion()) {
            object->Update(time);
        }
    }

    // Procesar colisiones delegando la responsabilidad a cada objeto
    for (auto* object : gameObjects) {
        if (object) {
            object->ProcessCollisions(gameObjects); // Cada objeto revisa sus colisiones
        }
    }

    // Eliminar objetos marcados para eliminación
    for (auto it = gameObjects.begin(); it != gameObjects.end(); ) {
        if ((*it)->IsMarkedForDeletion()) {
            delete* it; // Libera memoria
            it = gameObjects.erase(it); // Elimina el puntero de la lista
        }
        else {
            ++it;
        }
    }
    
    // Verificar y cambiar de escena si es necesario
    if (activeScene == gameScene) {
        if (player1->GetHealth() == 0) {
            activeScene = defeatScene;  // Cambia a la escena del menú
            std::cout << "Escena cambiada a menuScene" << std::endl;
            
        }
    }
    if (activeScene == gameScene) {
        if (player1->GetEnergy() == 10) {
            activeScene = winScene;  // Cambia a la escena del menú
            std::cout << "Escena cambiada a menuScene" << std::endl;

        }
    }
}
void Game::RestartGame() {
    // Limpiar todos los objetos del juego
    for (auto* object : gameObjects) {
        delete object;
    }
    gameObjects.clear();

    // Limpiar y reinicializar las escenas
    for (auto* scene : scenes) {
        delete scene;
    }
    scenes.clear();

    // Reejecutar el método Init para reiniciar todo
    Init();
    activeScene = gameScene;
}

void Game::AddGameObject(Solid* object) {
    gameObjects.push_back(object);
}

void Game::ProcessKeyPressed(unsigned char key, int px, int py) {
    cout << "tecla pulsada: " << key << endl;

    /*if (key >= '1' && key <= '0' + scenes.size()) {
        int index = (key - '0') - 1;
        this->activeScene = this->scenes[index];
    }*/

    if (activeScene) {
        activeScene->ProcessKeyPressed(key, px, py);

        // Cambiar de la escena del menú a la escena 2 al presionar 'P'
        if (activeScene == menuScene && (key == 'P' || key == 'p')) {
            std::cout << "Iniciando el juego jeje..." << std::endl;
            activeScene = gameScene; // Cambia a la escena 2
            RestartGame();
        }
        if (activeScene == defeatScene && (key == 'P' || key == 'p')) {
            std::cout << "Iniciando el juego jeje..." << std::endl;
            activeScene = gameScene;
            RestartGame();
        }
        if (activeScene == winScene && (key == 'P' || key == 'p')) {
            std::cout << "Iniciando el juego jeje..." << std::endl;
            activeScene = gameScene;
            RestartGame();
        }
    }
}

void Game::ProcessMouseClicked(int button, int state, int x, int y) {
    cout << "[GAME] Click:" << button << endl;
}

void Game::ProcessMouseMovement(int x, int y) {
    cout << "[GAME] Movement:" << x << ", " << y << endl;
}