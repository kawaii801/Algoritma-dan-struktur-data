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

void CreateEmpty(Tree *P){
    *P = NULL;
}

bool IsEmpty(Tree P){
    return (P == NULL);
}

address Allocation(infotype x){
    address P = (ElmtTree*)malloc(sizeof(ElmtTree));
    Info(P) = x;
    Right(P) = NULL;
    Left(P) = NULL;

    return P;
}

void Deallocation(address hapus){
    free(hapus);
}

bool IsOneElmt(Tree P){
    if(P != NULL){
        return(Right(P) == NULL && Left(P) == NULL);
    }else{
        return false;
    }
}

bool IsUnerLeft(Tree T){
    if(T != NULL){
        return(Left(T) != NULL && Right(T) == NULL);
    }else{
        return false;
    }
}

bool IsUnerRight(Tree T){
    if(T != NULL){
        return(Left(T) == NULL && Right(T) != NULL);
    }else{
        return false;
    }
}

bool IsBiner(Tree T){
    if(T != NULL){
        return(Left(T) != NULL && Right(T) != NULL);
    }else{
        return false;
    }
}

int JumlahElmt(Tree T){
    if(IsEmpty(T)){
        return 0;
    }else{
        return (1 + JumlahElmt(Left(T)) + JumlahElmt(Right(T)));
    }
}

int JumlahDaun(Tree T){
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

void AddBinaryTree(Tree *P, infotype x){
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
    Tree T;
    CreateEmpty(&T);

    AddBinaryTree(&T,30);
    AddBinaryTree(&T,10);
    AddBinaryTree(&T,5);
    AddBinaryTree(&T,17);
    AddBinaryTree(&T,2);
    AddBinaryTree(&T,3);
    AddBinaryTree(&T,20);
    AddBinaryTree(&T,13);
    AddBinaryTree(&T,15);
    AddBinaryTree(&T,7);
    AddBinaryTree(&T,12);
    cout << "PreOrder" << endl;
    PrintPreOrder(T);
    cout << endl << "InOrder" << endl;
    PrintInOrder(T);
    cout << endl << "PostOrder" << endl;
    PrintPostOrder(T);
    
    cout << endl << "Jumlah Elment : " << JumlahElmt(T);
    cout << endl << "Jumlah Daun : " << JumlahDaun(T);
    return 0;
}
