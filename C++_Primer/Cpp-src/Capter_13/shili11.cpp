#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>

class Folder;

class FolderpComp {
public:
	bool operator()(Folder* const& lhs, Folder* const& rhs);
};

class File {
	friend void swap(File&, File&);
public:
	File(const std::string& fname = "", const std::string& str = "") :
		filename(fname), contents(str) {}
	File(const File& item);
	~File();

	File& operator=(const File& item);

	void save(Folder&);
	void remove(Folder&);
	std::ostream& include_folders(std::ostream& os = std::cout);
	std::string get_contents(void) const {
		return contents;
	}

	std::string filename;
private:
	void add_to_Folders(void);//当this添加/移除到/出folders中包含所指向的Folder对象的files容器中
	void remove_from_Folders(void);
	std::string contents;
	std::set<Folder*, FolderpComp> folders;//两个相同的文件不可能放在一个相同的文件夹中，所以没有选multiset
};

class FilepComp {
public:
	bool operator()(File* const& lhs, File* const& rhs) {
		return lhs->filename < rhs->filename;
	}
};

class Folder {
public:
	Folder(const std::string& fname = "") :
		foldername(fname) {}
	~Folder();

	void addFile(File*);
	void removeFile(File*);
	std::ostream& include_files(std::ostream& os = std::cout);

	std::string foldername;
private:
	void remove_from_Files(void);
	std::multiset<File*, FilepComp> files;
};

bool FolderpComp::operator()(Folder* const& lhs, Folder* const& rhs) {
	return lhs->foldername < rhs->foldername;
}

void File::save(Folder& item) {
	folders.insert(&item);
	item.addFile(this);
}

void File::remove(Folder& item) {
	folders.erase(&item);
	item.addFile(this);
}

void File::add_to_Folders(void) {
	for (auto& elem : folders)
		elem->addFile(this);
}

void File::remove_from_Folders(void) {
	//删除的时候是根据file的filename删除的，因为Folder对象中可以添加多个相同文件名给的文件，这是好处，但是在删除的时候是根据file所指向的name匹配而删除的
	for (auto& elem : folders)
		elem->removeFile(this);
    folders.clear();
}

File::File(const File& item) :
	filename(item.filename + "_cpy"), contents(item.contents), folders(item.folders) {
	add_to_Folders();
}

File::~File() {
	remove_from_Folders();
}

File& File::operator=(const File& item) {
	remove_from_Folders();
	filename = item.filename + "_cpy";
	contents = item.contents;
	folders = item.folders;
	add_to_Folders();
	return *this;
}

void Folder::addFile(File* pfile) {
	files.insert(pfile);
}

void Folder::removeFile(File* pfile) {
	files.erase(pfile);
}

void Folder::remove_from_Files(void) {
	for (auto& elem : files)
		elem->remove(*this);
}

Folder::~Folder() {
	remove_from_Files();
}

std::ostream& Folder::include_files(std::ostream& os) {
	os << foldername << std::endl;
	for (const auto& elem : files)
		os << "    |____" << elem->filename << ": " << elem->get_contents() << std::endl;
	return os;

}

std::ostream& File::include_folders(std::ostream& os) {
	os << filename << std::endl;
	for (const auto& elem : folders)
		os << "    |____" << elem->foldername << std::endl;
	return os;
}

void swap(File& lhs, File& rhs) {
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();
	using std::swap;
	//不交换文件名字、文件内容，但是交换file所挂载的文件夹
	swap(lhs.folders, rhs.folders);
	lhs.add_to_Folders();
	rhs.add_to_Folders();
}

int main(void)
{
	Folder fold1("folder_1"), fold2("folder_2");
	File file1("file_1", "show me the world"), file2("file_2", "hello world"), file3("file_3", "hehe"), file4("file_4", "jokers");
	file1.save(fold1);
	file1.save(fold2);
	file2.save(fold2);
	file3.save(fold1);
	file4.save(fold2);

	File file5 = file1;//新文件file5是file1的拷贝，挂载点与file1相同
	fold1.include_files() << std::endl;
	fold2.include_files() << std::endl;
	file1.include_folders() << std::endl;
	std::cout << "------------------------" << std::endl;

	std::cout << std::endl;
	file5 = file2;//file5是file2的副本，挂载点与file2相同

	fold1.include_files() << std::endl;
	fold2.include_files() << std::endl;

	file1.include_folders() << std::endl;

	std::cout << "------------------------" << std::endl;

	swap(file5, file3);//交换file5与file3的挂载点
	fold1.include_files() << std::endl;
	fold2.include_files() << std::endl;

	return 0;
}
