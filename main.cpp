#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
sf::SoundBufferRecorder recorder;
//sf::SoundBufferRecorder recorder;
sf::SoundBuffer buffer;
std::ofstream outputFile;
void startRecording()
{
    recorder.start();
    std::cout << "Recording started." << std::endl;
}
void stopRecording()
{
    recorder.stop();
    const sf::SoundBuffer &buffer = recorder.getBuffer();
    buffer.saveToFile("Aecording.ogg");

    // buffer = recorder.getBuffer();
    // outputFile.open("audio.wav", std::ios::binary);
    // outputFile.write((const char*)buffer.getSamples(), buffer.getSampleCount() * sizeof(sf::Int16));
    // outputFile.close();
    // std::cout << "Recording stopped and saved to audio.wav." << std::endl;
}
void showAudioInfo(const std::string& filename)
{
    sf::SoundBuffer soundBuffer;
    if (soundBuffer.loadFromFile(filename))
    {
        std::cout << "Audio file: " << filename << std::endl;
        std::cout << "Duration: " << soundBuffer.getDuration().asSeconds() << " seconds" << std::endl;
        std::cout << "Bitrate: " << soundBuffer.getSampleRate() * soundBuffer.getChannelCount() * sizeof(sf::Int16) * 8 << " bits per second" << std::endl;
    }
    else
    {
        std::cout << "Failed to load audio file: " << filename << std::endl;
    }
}
void playRecording(const std::string& filename)
{
    sf::Sound sound;
    sf::SoundBuffer soundBuffer;
    if (soundBuffer.loadFromFile(filename))
    {
        sound.setBuffer(soundBuffer);
        sound.play();
        std::cout << "Playing audio file: " << filename << std::endl;
        while (sound.getStatus() == sf::Sound::Playing)
        {
            // Wait for the sound to finish playing
        }
    }
    else
    {
        std::cout << "Failed to load audio file: " << filename << std::endl;
    }
}
void showAllAudio()
{
    std::vector<std::string> filenames = { "audio.wav" }; // Change this to match the filenames of your saved audio
    if (filenames.empty())
    {
        std::cout << "No audio files found." << std::endl;
    }
    else
    {
        std::cout << "Found " << filenames.size() << " audio files:" << std::endl;
        for (const auto& filename : filenames)
        {
            std::cout << filename << std::endl;
        }
    }
}
void deleteAudio(const std::string& filename)
{
    if (std::remove(filename.c_str()) == 0)
    {
        std::cout << "Deleted audio file: " << filename << std::endl;
    }
    else
    {
        std::cout << "Failed to delete audio file: " << filename << std::endl;
    }
}
int main()
{
    std::string command;
    while (true)
    {
        std::cout << "Enter command (start, stop, info, play, list, delete, quit): ";
        std::cin >> command;
        if (command == "start")
        {
            startRecording();
        }
        else if (command == "stop")
        {
            stopRecording();
        }
        else if (command == "info")
        {
            std::string filename;
            std::cout << "Enter audio filename: ";
            std::cin >> filename;
            showAudioInfo(filename);
        }
        else if (command == "play")
        {
            std::string filename;
            std::cout << "Enter audio filename: ";
            std::cin >> filename;
            playRecording(filename);
        }
        else if (command == "list")
        {
            std::cout << "Listing audio files...\n";
            // TODO: Implement code to list audio files
        }
        else if (command == "delete")
        {
            std::string filename;
            std::cout << "Enter audio filename to delete: ";
            std::cin >> filename;
            // TODO: Implement code to delete audio file
        }
        else if (command == "quit")
        {
            std::cout << "Exiting program...\n";
            break;
        }
        else
        {
            std::cout << "Invalid command. Please try again.\n";
        }
    }
    return 0;
}







// #include <SFML/Graphics.hpp>
// #include <SFML/Audio.hpp>
// #include<iostream>

// // #include <SFML/Audio.hpp>
// // #include <iostream>
// // #include <fstream>
// // #include <vector>
// // #include <string>
// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");

//     if(!sf::SoundBufferRecorder::isAvailable())
//     {
//         // error
//     }
//     sf::SoundBufferRecorder recorder;
//     recorder.start();

//                       //** start music

//     // sf::Music music;
//     // if(!music.openFromFile("file_example_OOG_2MG.ogg"))
//     //  {
//     //     std::cout<<"error"<<std::endl;
//     // }
//     //  music.play();


//                       //** sound play
//     // sf::SoundBuffer buffer;
//     // if(!buffer.loadFromFile("ocean-wave-1.wav"))
//     // {
//     //     std::cout<<"error"<<std::endl;
//     // }
//     // sf::Sound sound;
//     // sound.setBuffer(buffer);
//     // sound.play();




//     // sf::CircleShape circle(150); // drae the circle
//     // circle.setFillColor(sf::Color::Cyan);
//     // sf::CircleShape shape(100.f);
//     // shape.setFillColor(sf::Color::Green);
                                               
//     //                                            //**** Adding A sprite*****
//     //           sf::Texture texture;
//     // //texture.setRepeated(true);   //repeted ke liye
//     //             if(!texture.loadFromFile("images.jpeg"))
//     //             {
//     //                 std::cout<<"error loading"<<std::endl;
//     //             }
//     // // sf::Sprite sprite(texture);
//     //             sf::Sprite sprite;
//     //             sprite.setTexture(texture);
//     // sprite.setScale(sf::Vector2f(0.5,4));  // set scale
//     // sprite.setRotation(45);  // position rotate
//     // sprite.setPosition(sf::Vector2f(200,200)); // position
//     //sprite.setTextureRect(sf::IntRect(0,0,600,600)); // size ke liye
                                                 

//     while ( window.isOpen() )
//     {
//         sf::Event event;
//         while ( window.pollEvent(event) )
//         {
//            switch (event.type)
//            {
//            case sf::Event::Closed:
           
//            recorder.stop();
//            const sf::SoundBuffer &buffer = recorder.getBuffer();
//            buffer.saveToFile("recording.ogg");

//             window.close();
//             break;
//                                                /* case has been keyword ******
//         //    case sf::Event::KeyPressed:
//         //    std::cout<<"key has been pressed"<<std::endl;
//         //    switch(event.key.code)
//         //    {
//         //     case sf::Keyboard::A:
//         //     std::cout<<"A"<<std::endl;
//         //     break;
//         //    }
//         //    break;

//         //    case sf::Event::KeyReleased:
//         //    std::cout<<"key has been released"<<std::endl;
//         //    break;                                            */

//                                                                    //*** Mouse Event****

//             //  case sf::Event::MouseButtonPressed:
//             //  std::cout<<"mouse is pressed"<<std::endl;
//             //  switch(event.key.code)
//             //  {
//             //     case sf::Mouse::Left:
//             //                  std::cout<<"mouse is left pressed"<<std::endl;
//             //                  break;

//             //  }
//             // break;      
                                                  

//                                                                   //**** joystic buttom ********

//             // case sf::Event::JoystickConnected:   
//             // std::cout<<"joystic is connected"<<std::endl;

//             // break;
//             // case sf::Event::JoystickDisconnected:
//             //             std::cout<<"joystic is disconnected"<<std::endl;
//             //             break;

//             //     case sf::Event::JoystickButtonPressed:   
//             // std::cout<<"joystic button is pressed"<<std::endl;
//             // break;
                                                                 


//                                                             // ***  windows event ***
//         //   case sf::Event::Resized:
//         //   std::cout<<event.size.width<<" : "<<event.size.height<<std::endl;
//         //   break;
        
//         //   case sf::Event::LostFocus:
//         //   std::cout<<"lost focus"<<std::endl;
//         //   break;

//         //   case sf::Event::GainedFocus:
//         //   std::cout<<"Gained focus"<<std::endl;
//         //   break;
         
//                                                       // ****Test Event ****
        
//         // case sf::Event::TextEntered:
//         // std::cout<<"text ha been entered"<<std::endl;
//         // if(event.text.unicode==65)
//         // {
//         //     std::cout<<"Capital A has been pressed";
//         // }
//         // break;
        
//            }
//         }
//                                              //****** Live keybord input *****
//         //  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
//         //  {
//         //        std::cout<<"jump player"<<std::endl;
//         //  }

//         window.clear();
//         // window.draw(circle);
//         //window.draw(sprite);
//         window.display();
//     }

//     return 0;
// }







// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(200,200), "Hello From SFML");
//     sf::CircleShape shape(100.f);
//     shape.setFillColor(sf::Color::Magenta);

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if(event.type == sf::Event::Closed){
//                 std::cout<<"key has been pressed"<<std::endl;
//                 window.close();
//             }
//         }
//         window.clear();
//         window.draw(shape);
//         window.display();
        
//     }

//     return 0;
// }