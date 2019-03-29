#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct TElmtTree *address;
typedef struct TElmtTree{
    infotype info;
    address left;
    address right;
}ElmtTree;

typedef address Tree;

#define Info(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right

void CreateEmpty(Tree *P){ //membuat tree kosong
    *P = NULL;
}

bool IsEmpty(Tree P){ //mengecek apakah tree kosong
    return (P == NULL);
}

address Allocation(infotype x){ //membuat node baru
    address P = (ElmtTree*)malloc(sizeof(ElmtTree));
    Info(P) = x;
    Right(P) = NULL;
    Left(P) = NULL;

    return P;
}

void Deallocation(address hapus){ //dealokasi suatu node
    free(hapus);
}

bool IsOneElmt(Tree P){ //mengecek apakah tree hanya satu elemen, tidak punya kaki sebelah kiri dan kanan
    if(P != NULL){
        return(Right(P) == NULL && Left(P) == NULL);
    }else{
        return false;
    }
}

bool IsUnerLeft(Tree T){ //ngecek apa kaki kiri ada dan kaki kanan tidak ada
    if(T != NULL){
        return(Left(T) != NULL && Right(T) == NULL);
    }else{
        return false;
    }
}

bool IsUnerRight(Tree T){ //ngecek apa kaki kanan ada dan kiri tidak ada
    if(T != NULL){
        return(Left(T) == NULL && Right(T) != NULL);
    }else{
        return false;
    }
}

bool IsBiner(Tree T){ //ngecek apa dua kaki ada semua
    if(T != NULL){
        return(Left(T) != NULL && Right(T) != NULL);
    }else{
        return false;
    }
}

int JumlahElmt(Tree T){ //menghitung banyaknya elemen
    if(IsEmpty(T)){
        return 0;
    }else{
        return (1 + JumlahElmt(Left(T)) + JumlahElmt(Right(T)));
    }
}

int JumlahDaun(Tree T){ //menghitung banyaknya daun (node paling bawah yang tidak punya kaki)
    if(IsOneElmt(T)){
        return 1;
    }else{
        if(IsUnerLeft(T)){
            return JumlahDaun(Left(T));
        }else if(IsUnerRight(T)){
            return JumlahDaun(Right(T));
        }else{
            return JumlahDaun(Left(T)) + JumlahDaun(Right(T));
        }
    }
}

void InsertLeft(Tree *P, infotype x, infotype base){ //memasukkan node baru hasil alokasi x di sebelah kiri node yang berinfo kan base
    if(*P == NULL){

    }else if(Info(*P) == base){
            if(Left(*P) == NULL){
                address temp = Allocation(x);
                Left(*P) = temp;
            }   
    }else{
        InsertLeft(&(Left(*P)),x,base);
        InsertLeft(&(Right(*P)),x,base);
    }
}

void InserRight(Tree *P, infotype x, infotype base){ //memasukkan node baru hasil alokasi x di sebelah kanan node yang berinfo kan base
    if(*P == NULL){

    }else if(Info(*P) == base){
            if(Right(*P) == NULL){
                address temp = Allocation(x);
                Right(*P) = temp;
            }   
    }else{
        InserRight(&(Right(*P)),x,base);
        InserRight(&(Left(*P)),x,base);
    }
}

void AddBinaryTree(Tree *P, infotype x){ //memasukkan node secara binary
    if(IsEmpty(*P)){
        address temp = Allocation(x);
        *P = temp;
    }
    if(Info(*P) > x){
        AddBinaryTree(&(Left(*P)),x);
    }else if(Info(*P) < x){
        AddBinaryTree(&(Right(*P)),x);
    }
}

void PrintPreOrder(Tree T){
    if(IsEmpty(T)){

    }else{
        cout << Info(T) << " ";
        PrintPreOrder(Left(T));
        PrintPreOrder(Right(T));
    }
}

void PrintInOrder(Tree T){
    if(IsEmpty(T)){

    }else{
        PrintInOrder(Left(T));
        cout << Info(T) << " ";
        PrintInOrder(Right(T));
    }
}

void PrintPostOrder(Tree T){
    if(IsEmpty(T)){

    }else{
        PrintPostOrder(Left(T));
        PrintPostOrder(Right(T));
        cout << Info(T) << " ";
    }
}

int main(){
    return 0;
    cout << "Test";
}
