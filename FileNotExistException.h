#pragma once
#include "FileException.h"

class FileNotExistException : public FileException {
public:
	FileNotExistException(const char* FileName, int Code = 7, const char* Message = "FileNotOpenException") :
		FileException(Code, Message, FileName) {
	}
	friend ostream& operator<<(ostream& out, FileNotExistException& exc) {
		cout << "File " << exc.FileName << " not exist" << endl;
		out << dynamic_cast<FileException&>(exc);
		return out;
	}
};