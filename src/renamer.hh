#ifndef RENAMER_HH
# define RENAMER_HH

# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <iostream>
# include <string>
# include <list>
# include <stdio.h>

class Renamer
{
  public:
    Renamer(std::string directory, std::string file_type);
    ~Renamer();
    void find_files();
    void rename_subtitle(Renamer* to_rename);
    std::list<std::string> get_list();
    void set_list(std::list<std::string> to_set);
    std::string get_file_type();
    void print_list();

  private:
    bool check_file(std::string file_name);

  private:
    std::string directory_;
    std::string file_type_;
    std::list<std::string> files_;

};

#endif /* RENAMER_HH */
