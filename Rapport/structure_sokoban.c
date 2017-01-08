struct une_case{
   int val;
  };

  struct sokoban{
    int mode;
    CASE une_case[100][100]; //ne devrais jamais depasser 100*100 cases
    int niveau;
    };
