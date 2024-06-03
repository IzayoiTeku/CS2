//
//  ASTree.cpp
//  Abstract Syntax Tree
//
//  Created by Jonathan Maletic
//  Copyright 2024 Kent State University. All rights reserved.
//  Spring 2024
//  srcML 1.0
//
//  Modified by: Peter Nguyen
//
//

#include "ASTree.hpp"
#include "profile.hpp"


// Copy constructor for srcML
//
srcML::srcML(const srcML& actual) {  ASTree_cpp.count(__LINE__, "ctor");
    header = actual.header;
    if (actual.tree)
        tree   = new AST(*(actual.tree));
    else
        tree = 0;
}

// Constant time swap for srcML
//
void srcML::swap(srcML& b) { ASTree_cpp.count(__LINE__, "swap");
    std::string t_header = header;
    header = b.header;
    b.header = t_header;
    
    AST *temp = tree;
    tree = b.tree;
    b.tree = temp;
}

// Assignment for srcML
//
srcML& srcML::operator=(srcML rhs) { ASTree_cpp.count(__LINE__, "assign");
    swap(rhs);
    return *this;
}

// Reads in and constructs a srcML object.
//
std::istream& operator>>(std::istream& in, srcML& src){  ASTree_cpp.count(__LINE__, "input");
    char ch;
    if (!in.eof()) in >> ch;
    src.header = readUntil(in, '>');
    if (!in.eof()) in >> ch;
    if (src.tree) delete src.tree;
    src.tree = new AST(category, readUntil(in, '>'));
    src.tree->read(in);
    return in;
}

// Prints out a srcML object
//
std::ostream& operator<<(std::ostream& out, const srcML& src){ ASTree_cpp.count(__LINE__, "output");
    if (src.tree) src.tree->print(out);
    return out;
}

//  Adds in the includes and profile object declarations
//
void srcML::mainHeader(const std::vector<std::string>& profileName,
                       const std::vector<std::string>& fileName    ) { ASTree_cpp.count(__LINE__, "mainHeader");
    tree->mainHeader(profileName, fileName);

    // #include "profile.hpp"
    // profile foo.cpp("foo.cpp")
    // ...
    std::list<AST*>::iterator ptr = child.begin(); // how to make iterator
    for (size_t i = 0; i <profileName.size(); ++i){
        std::string line = "profile" + profileName[i] + "(\"" + filename[i] + "\"); "
        ptr = child.insert(ptr, new AST(token, line));
    }


}

//  Adds in the includes and declares profile object declarations
//
void srcML::fileHeader(const std::string& profileName) { ASTree_cpp.count(__LINE__, "fileHeader");
    tree->fileHeader(profileName);
}

// Adds in the report to the main
//
void srcML::mainReport(const std::vector<std::string>& profileName) { ASTree_cpp.count(__LINE__, "mainReport");
        tree->mainReport(profileName);
}

///  Inserts a profile.count() into each function body.
//
void srcML::functionCount(const std::string& profileName) {  ASTree_cpp.count(__LINE__, "functionCount");
    tree->functionCount(profileName);
}

// Inserts a profile.count() for each statement.
//
void srcML::lineCount(const std::string& profileName) { ASTree_cpp.count(__LINE__, "lineCount");
    tree->lineCount(profileName);
}

    

//
//AST::
//


// Constructs a category, token, or whitespace node for the tree.
//
AST::AST(nodes t, const std::string& s) { ASTree_cpp.count(__LINE__, "ctor");
    nodeType = t;
    switch (nodeType) {
        case category:
            tag = s;
            break;
        case token:
            text = unEscape(s);
            break;
        case whitespace:
            text = s;
            break;
    }
}


// Destructor for AST
//
AST::~AST() { ASTree_cpp.count(136, "dtor");
    //TODO: IMPLEMENT
    //Recursively traverse tree and delete from bottom up
    if(nodeType == category) {
        for(std::list<AST*>::iterator i = child.begin(); i != child.end(); ++i) {
            delete (*i);
        }
    }
    

}


// Copy Constructor for AST
//
AST::AST(const AST& actual) { ASTree_cpp.count(__LINE__, "copyctor");
    //TODO: IMPLEMENT
    //Recursively traverse actual and
    //make a copy of each node putting it
    //into this.
    // Duplicate it
    nodeType = actual.nodeType;
    tag = actual.tag;
    closeTag = actual.closeTag;
    text = actual.text;

    for (std::list<AST*>::const_iterator it = actual.child.begin(); it != actual.child.end(); ++it) {
        child.push_back(new AST(**it));
	}
}


// Constant time swap for AST
//
void AST::swap(AST& rhs) { ASTree_cpp.count(__LINE__, "swap");
    //TODO: IMPLEMENT
    //Swap all the top level childern (pointers to AST)
    std::swap(nodeType, rhs.nodeType);
    std::swap(tag, rhs.tag);
    std::swap(closeTag, rhs.closeTag);
    std::swap(text, rhs.text);

    child.swap(b.child);
    // if(!child.empty) {
    //     for(std::list<AST*>::iterator i = child.begin(); i != child.end(); ++i) {
    //         delete (*i);
    //     }
    // }


}

/// Assignment for AST
//
AST& AST::operator=(AST rhs) { assign.count(__LINE__, "assign");
    swap(rhs);
    return *this;
}


// REQUIRES: this->nodetype == category && tagName is valid srcML tag
// ENSURES: RETVAL == this->child[i] where this->child[i]->tag == tagName
//
// IMPORTANT for milestone 2 and 3
//
AST* AST::getChild(std::string tagName) { ASTree_cpp.count(__LINE__, "getChild");
    std::list<AST*>::iterator ptr = child.begin();
    while (((*ptr)->tag != tagName) && (ptr != child.end())) {
         ++ptr;
    }
    return *ptr;
}


// REQUIRES: this->tag == "name"
// Returns the full name of a <name> node
//  There are two types of names in srcML.  A simple name (e.g., foo) and a
//   name with a scope (e.g., std::bar).  This returns the correct
//   one from <name> AST node.
//
// IMPORTANT for milestone 3
//
std::string AST::getName() const { ASTree_cpp.count(__LINE__, "getName");
    std::string result;
    if (child.front()->tag != "name") {
        result = child.front()->text;   //A simple name (e.g., main)
    } else {                            //A complex name (e.g., stack::push).
        result = child.front()->child.front()->text;
        result += "::";
        result += child.back()->child.front()->text;
    }
    return result;
}


//  Adds above the main, in the main file:
//  1. #include "profile.hpp"
//  2. All needed profile object declarations
//      example: profile foo_cpp("foo.cpp");
//
void AST::mainHeader(const std::vector<std::string>& profileName,
                     const std::vector<std::string>& fileName     ) { ASTree_cpp.count(__LINE__, "mainHeader");

    //TODO: IMPLEMENT
    //Skip down a couple lines or find main and put it before it
    //Add a node with #include "profile.hpp"
    //For each file profile name, add a node with a profile
    //   declaration "profile foo_cpp("foo.cpp");"
    std::cerr << "1" << std::endl;
	std::list<AST*>::iterator index = child.begin();

	// Iterate until it finds a function
	while ((*index)->tag != "function") {
		++index;
	}
	std::cerr << "2" << std::endl;

	fileName("#include \"profile.hpp\"\nprofile functions;\n");

	std::cerr << "3" << std::endl;
    for (size_t i = 0; i <profileName.size(); ++i){
        std::string line = "profile" + profileName[i] + "(\"" + filename[i] + "\"); "
    }
	std::cerr << "4" << std::endl;

	fileName += "\n";

	std::cerr << "5" << std::endl;
	child.insert(index, new AST(token, fileName));
	std::cerr << "6" << std::endl;
}


//  Adds in each file (except main file):
//  1. #include "profile.hpp"
//  2. All needed external profile object declarations
//      example: extern profile thisfile_cpp;
//
void AST::fileHeader(const std::string& profileName) { ASTree_cpp.count(__LINE__, "fileHeader");

    //TODO: IMPLEMENT
    //Skip down a couple lines or find first function and put it before it
    //Add #include "profile.hpp"
    //Add in the external declaration for that file "extern profile foo_cpp;"
    std::list<AST*>::iterator itr = child.begin();
	while((*itr)->tag != "function") {
		++itr;
	}

	// create string to insert
	std::string profileString("#include \"profile.hpp\"\nextern profile functions;\n");

	for(std::vector<std::string>::iterator nameItr = profileName.begin(); nameItr < profileName.end(); ++nameItr) {
	    profileString = profileString + "extern profile " + *nameItr + ";\n";
	}

	profileString += "\n";

	// insert new child AStree
	child.insert(itr, new AST(token, profileString));
}


// Adds in the report to the main file
// Assumes only one return in the main
//
void AST::mainReport(const std::vector<std::string>& profileName) { ASTree_cpp.count(__LINE__, "mainReport");
    
    //TODO: IMPLEMENT
    //Find the function with name of "main" in the file
    // -Get the "block" node of this function
    // -Set an iterator to the child.end() of "block"
    // -Decrement it once (to skip the "}")
    // -Search backwards for a "return" tag
    // -Insert the report statements before the return
    
    // Find a "main" file
    std::list<AST*>::iterator itr = child.begin();
	while((*itr)->tag != "main") {
		++itr;
	}

    // Search backwards for "return tag"
	std::vector<std::string>::iterator getBlock = child.end(); 
    --getBlock;
    while(getBlock->tag != "return"){
        --getBlock;
    }
    
    // Insert report statements
    profileName.insert(getBlock, text);

}


// Adds a node to the function block to count the times each function
//  is executed
//  Assumes no nested functions
//
void AST::functionCount(const std::string& profileName) { ASTree_cpp.count(__LINE__, "functionCount");
    
    //TODO: IMPLEMENT
    // for each child in the "unit"
    //     if child is a function, constructor, destructor
    //        Find the function name (use AST::getName())
    //        Find <block>, then find <block_content>
    //        Insert the count as first child in <block_content>
    //        Example: main1_cpp.count(__LINE__, "main");

    for(size_t i = 0; i < child.size(); ++itr) {
	    if (child->tag = "ASTree_cpp") {
            std::string functionName = profileName.getName();
            profileName.find("<block>");
            profileName.find("<block_content>");
            
            profileName.insert(count(), "<block_content>");
            
        }

    }
}


// Adds in a node to count the number of times each statement is executed
//   Do not count breaks, returns, throw, declarations, etc.
//   Assumes all construts (for, while, if) have an explicit block { }
//
void AST::lineCount(const std::string& profileName) { ASTree_cpp.count(__LINE__, "lineCount");
    
    //TODO: IMPLEMENT
    // Recursively check for expr_stmt within all category nodes <block>
    // Very similar to AST::print
    // For each child:
    //   If it is a category node
    //       If it is a expr_stmt insert a count after it
    //          Example: foo_cpp.count(__LINE__);
    //       Else call lineCount if not a stop tag  See isStopTag()
    //   Else (token or whitespace) do nothing
    for (std::list<AST*>::const_iterator i = child.begin(); i != child.end(); ++i) {
        if ((*i)->nodeType == category){
            if(expr_stmt) profileName.insert(count, expr_stmt);
            else if(!isStopTag(profileName)) lineCount(profileName);
        }
        
            
    }

    
}

// Returns TRUE if the tag (syntactic category) is not to be profiled
//
// IMPORTANT for milestone 3
//
bool isStopTag(std::string tag) { ASTree_cpp.count(__LINE__, "isStopTag");
    if (tag == "condition"             ) return true; //Remove for challenge
    if (tag == "type"                  ) return true;
    if (tag == "name"                  ) return true;
    if (tag == "return"                ) return true;
    if (tag == "break"                 ) return true;
    if (tag == "continue"              ) return true;
    if (tag == "parameter_list"        ) return true;
    if (tag == "decl_stmt"             ) return true;
    if (tag == "argument_list"         ) return true;
    if (tag == "init"                  ) return true;
    if (tag == "cpp:include"           ) return true;
    if (tag == "macro"                 ) return true;
    if (tag == "comment type=\"block\"") return true;
    if (tag == "comment type=\"line\"" ) return true;
    return false;
}


// Print an AST
// Preorder traversal that prints out leaf nodes only (tokens & whitesapce)
//
std::ostream& AST::print(std::ostream& out) const { ASTree_cpp.count(__LINE__, "print");
    for (std::list<AST*>::const_iterator i = child.begin(); i != child.end(); ++i) {
        if ((*i)->nodeType != category)
            out << (*i)->text;   //Token or whitespace node, print it
        else
            (*i)->print(out);    //Category node, recursive call
    }
    return out;
}


// Read in and construct AST
// REQUIRES: '>' was previous charater read 
//           && this == new AST(category, "TagName")
//
std::istream& AST::read(std::istream& in) { ASTree_cpp.count(__LINE__, "read");
    AST *subtree;
    std::string temp, Lws, Rws;
    char ch;
    if (!in.eof()) in.get(ch);
    while (!in.eof()) {
        if (ch == '<') {                      //Found a tag
            temp = readUntil(in, '>');
            if (temp[0] == '/') {
                closeTag = temp;
                break;                        //Found close tag, stop recursion
            }
            subtree = new AST(category, temp);               //New subtree
            subtree->read(in);                               //Read it in
            in.get(ch);
            child.push_back(subtree);                        //Add it to child
        } else {                                             //Found a token
            temp = std::string(1, ch) + readUntil(in, '<');  //Read it in.
            std::vector<std::string> tokenList = tokenize(temp);
            for (std::vector<std::string>::const_iterator i=tokenList.begin();
                 i != tokenList.end();
                 ++i) {
                if (isspace((*i)[0])) {
                    subtree = new AST(whitespace, *i);
                } else {
                    subtree = new AST(token, *i);
                }
                child.push_back(subtree);
            }
            ch = '<';
        }
    }
    return in;
}



// Utilities for AST::read()

// Reads until a key is encountered.  Does not include ch.
// REQUIRES: in.open()
// ENSURES: RetVal[i] != key for all i.
std::string readUntil(std::istream& in, char key) { ASTree_cpp.count(__LINE__, "readUntil");
    std::string result;
    char ch;
    in.get(ch);
    while (!in.eof() && (ch != key)) {
        result += ch;
        in.get(ch);
    }
    return result;
}

// Converts escaped XML charaters back to charater form
// REQUIRES: s == "&lt;"
// ENSURES:  RetVal == "<"
std::string unEscape(std::string s) { unEscape.count(__LINE__, "unEscape");
    std::size_t pos = 0;
    while ((pos = s.find("&gt;"))  != s.npos) { s.replace(pos, 4, ">"); }
    while ((pos = s.find("&lt;"))  != s.npos) { s.replace(pos, 4, "<"); }
    while ((pos = s.find("&amp;")) != s.npos) { s.replace(pos, 5, "&"); }
    return s;
}

// Given: s == "   a + c  "
// RetVal == {"   ", "a", " ", "+", "c", " "}
std::vector<std::string> tokenize(const std::string& s) { ASTree_cpp.count(__LINE__, "tokenize");
    std::vector<std::string> result;
    std::string temp = "";
    unsigned i = 0;
    while (i < s.length()) {
        while (isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
        while (!isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
    }
    return result;
}
    

