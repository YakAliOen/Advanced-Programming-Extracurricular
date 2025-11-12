struct account {
    string username, name, email, password;
    account *next, *prev;
};

account *head=NULL, *tail=NULL, *cur, *baru;

account *create (string username, string name, string email, string password) {
    account *node = new account;
    node->username = username;
    node->name = name;
    node->email = email;
    node->password = password;
    node->next = NULL;
    node->prev = NULL;
    return node;
}





















//delete first
void deletefirst() {
    if (head == NULL) {
        cout << "List kosong, tidak ada yang dihapus.\n";
    } else {
        del = head;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete del;
        cout << "Data berhasil dihapus dari awal.\n";
    }
}

//delete last
void deletelast() {
    if (head == NULL) {
        cout << "List kosong, tidak ada yang dihapus.\n";
    } else {
        del = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete del;
        cout << "Data berhasil dihapus dari akhir.\n";
    }
}
