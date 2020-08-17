#include<iostream>
#include<string>
#include<set>

class Folder;

class Message {
	friend class Folder;
public:
	Message(const std::string& fname ="",const std::string&str=""):
		name(fname),contents(str){}
	Message(const Message&);
	~Message();
	Message& operator=(const Message& item);

	void save(Folder&);//将当前msg加入到给定Folder对象中，同时也将Folder对象的指针保存在folders成员中
	void remove(Folder&);
	std::ostream& include_file(std::ostream& os = std::cout) const;

	std::string name;
private:
	std::string contents;
	std::set<Folder*> folders;
	void add_to_Folders(void);//将当前的this指针加入到folders指向的Folder对象中的msg_pointer_set容器中
	void remove_from_Folders(void);//将当前的this指针从folders指向的Folder对象中的msg_pointer_set容器中移除
};



class Folder {
public:
	Folder(const std::string&fname):
		fold_name(fname){}

	void addMsg(Message*);
	void removeMsg(Message*);
	std::ostream& include_msg(std::ostream& os = std::cout) const;
public:
	std::string fold_name;
private:
	std::set<Message*> msg_pointer_set;
};

void Message::save(Folder& f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder& f)
{
	folders.erase(&f);
	f.removeMsg(this);
}

void Message::add_to_Folders(void)
{
	for (auto& fold : folders)
		fold->addMsg(this);
}

void Message::remove_from_Folders(void)
{
	for (auto& fold : folders)
		fold->removeMsg(this);
}

std::ostream& Message::include_file(std::ostream& os) const
{
	os << name << " includes in:" << std::endl;
	for (const auto& fold : folders)
		os << fold->fold_name << ' ';
	return os;
}

void Folder::addMsg(Message* msg_pointer)
{
	msg_pointer_set.insert(msg_pointer);
}

void Folder::removeMsg(Message* msg_pointer)
{
	msg_pointer_set.erase(msg_pointer);
}

std::ostream& Folder::include_msg(std::ostream& os) const
{
	os << fold_name << " includes msg:" << std::endl;
	for (auto riter = msg_pointer_set.rbegin(); riter != msg_pointer_set.rend(); ++riter)
		os << (*riter)->name << ' ';
	return os;
}

Message::Message(const Message& item) :
	name(item.name), contents(item.contents), folders(item.folders) {
	add_to_Folders();
}

Message::~Message()
{
	remove_from_Folders();
}

Message& Message::operator=(const Message& item)
{
	remove_from_Folders();
	name = item.name;
	contents = item.contents;
	folders = item.folders;
	add_to_Folders();
	return *this;
}

int main(void)
{
	Folder fold1("folder1"), fold2("folder2");
	Message msg1("msg1", "hello world"), msg2("msg2", "show me the world"), msg3("msg3", "talk is cheap"), msg4("msg4", "do something");
	msg1.save(fold1);
	msg2.save(fold2);
	msg2.save(fold1);
	msg3.save(fold2);
	msg4.save(fold1);

	fold1.include_msg() << std::endl;
	fold2.include_msg() << std::endl;
	msg2.include_file() << std::endl;
	msg2.include_file() << std::endl;

	return 0;
}
