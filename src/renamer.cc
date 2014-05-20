#include "renamer.hh"


Renamer::Renamer(std::string directory, std::string file_type)
{
  directory_ = directory;
  file_type_ = file_type;
}

Renamer::~Renamer()
{
}

void Renamer::find_files()
{
  DIR *dir;
  struct dirent *ent;
  if ((dir = opendir(directory_.c_str())) != nullptr)
  {
    while ((ent = readdir(dir)) != nullptr)
    {
      if (check_file(ent->d_name))
        files_.push_back(ent->d_name);
    }
    closedir(dir);
  }
  else
  {
    std::cerr << "Directory does not exist !";
  }

  files_.sort();
}

bool Renamer::check_file(std::string file_name)
{
  if (file_name.find(file_type_) != std::string::npos)
    return true;
  return false;
}

void Renamer::rename_subtitle(Renamer* to_rename)
{
  std::list<std::string> to_set;
  std::list<std::string>::iterator it = files_.begin();
  int result;
  std::string old_file;
  std::string new_file;
  for (auto file : to_rename->get_list())
  {
    std::string to_add = (*it);
    to_add = to_add.replace(to_add.length() - 3, 3, to_rename->get_file_type());
    to_set.push_back(to_add);
    old_file = directory_ + "/" + file;
    new_file = directory_ + "/" + to_add;
    

    result = rename(old_file.c_str(), new_file.c_str());
    if (result == 0)
      std::cout << old_file << " File renamed successfully to " << new_file << " !" << std::endl;
    else
      std::cerr << old_file << " File was not renamed to " << old_file << " !" << std::endl;
    it++;
  }
  to_rename->set_list(to_set);
}

void Renamer::print_list()
{
  for (auto e : files_)
    std::cout << e << std::endl;
}



std::list<std::string> Renamer::get_list()
{
  return files_;
}

void Renamer::set_list(std::list<std::string> to_set)
{
  files_ = to_set;
}


std::string Renamer::get_file_type()
{
  return file_type_;
}
