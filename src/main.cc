#include "renamer.hh"

/* 
 First argument : directory
 Second argument : video file
 Third argument : subtitle file
*/

int main(int argc, char** argv)
{
  if (argc > 3)
  {
    Renamer* renamer_video = new Renamer(argv[1], argv[2]);
    Renamer* renamer_subtitle = new Renamer(argv[1], argv[3]);

    renamer_video->find_files();
    renamer_subtitle->find_files();

    renamer_video->get_list().sort();
    renamer_subtitle->get_list().sort();

    renamer_video->print_list();
    renamer_subtitle->print_list();


    renamer_video->rename_subtitle(renamer_subtitle);

    delete renamer_video;
    delete renamer_subtitle;
  }
  else
    std::cerr << "Not enough arguments specified" << std::endl;
  return 0;
}
