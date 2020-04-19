class FileSystem {
   public:
    size_t numDisks() const;
};

// extern FileSystem tfs;
FileSystem& tfs() {
    static FileSystem fs;
    return fs;
}

class Directory {
   public:
    Directory();
};

Directory::Directory() { size_t disks = tfs().numDisks(); }

Directory tempDir() {
    static Directory td;
    return td;
}
