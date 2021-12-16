vector<pair<int, string>> x

  // container that supports output iterator operations, push_back and that holds <int,string> pairs
  copy(m.begin(), m.end(), back_inserter(x));

  // map doesn't support push_back so back_inserter is an invalid operation
  //copy(x.begin(), x.end(), back_inserter(m));