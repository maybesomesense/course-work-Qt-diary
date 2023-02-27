#pragma once
#include "FileException.h"

class FileNotFoundException : public FileException {
public:
	FileNotFoundException(int Code, const char* Message = "FileNotFoundException", const char* FileName = "") :
		FileException(Code, Message, FileName) {
	}
	friend ostream& operator<<(ostream& out, FileNotFoundException& exc) {
		out << "Can't find file " << exc.FileName << endl;
		out << dynamic_cast<FileException&>(exc);
		return out;
	}
};