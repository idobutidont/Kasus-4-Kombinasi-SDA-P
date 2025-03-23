#include "linked.h"
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define boolean bool


boolean isEmpty(address p) {
    return (p == NULL);
}

void Create_Node(address *p) {
    *p = (address)malloc(sizeof(ElmtList));
}

void Isi_Node(address *p, infotype nilai) {
    if (*p != NULL) {
        (*p)->info = nilai;
        (*p)->next = NULL;
    }
}

void Tampil_List(address p) {
    address temp = p;
    if (isEmpty(temp)) {
        printf("List Kosong\n");
    } else {
        while (temp != NULL) {
            printf("%d ", temp->info);
            temp = temp->next;
        }
        printf("\n");
    }
}

void Ins_Awal(address *p, address PNew) {
    PNew->next = *p;
    *p = PNew;
}

void Ins_Akhir(address *p, address PNew) {
    if (isEmpty(*p)) {
        *p = PNew;
    } else {
        address temp = *p;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = PNew;
    }
}

address Search(address p, infotype nilai) {
    address temp = p;
    boolean found = false;
    
    while (temp != NULL && !found) {
        if (temp->info == nilai) {
            found = true;
        } else {
            temp = temp->next;
        }
    }
    
    return temp;  
}

void InsertAfter(address *p, infotype nilai, address PNew) {
    if (!isEmpty(*p)) {
        address temp = Search(*p, nilai);
        
        
        if (temp != NULL) {
            
            PNew->next = temp->next;
            temp->next = PNew;
        }
        
    }
}

void Del_Awal(address *p, infotype *X) {
    if (!isEmpty(*p)) {
        address temp = *p;
        *X = temp->info;
        *p = temp->next;
        free(temp);  
    }
}

void Del_Akhir(address *p, infotype *X) {
    if (!isEmpty(*p)) {
        address temp = *p;
        address prev = NULL;
        
        
        if (temp->next == NULL) {
            *X = temp->info;
            *p = NULL;
            free(temp);  
        } else {
            
            while (temp->next != NULL) {
                prev = temp;
                temp = temp->next;
            }
            *X = temp->info;
            prev->next = NULL;
            free(temp);  
        }
    }
}

void Del_After(address *pBef, infotype *X) {
    if (!isEmpty(*pBef) && (*pBef)->next != NULL) {
        address temp = (*pBef)->next;
        *X = temp->info;
        (*pBef)->next = temp->next;
        free(temp);  
    }
}

void DeAlokasi(address *p) {
    free(*p);
    *p = NULL;
}

int NbElmt(address p) {
    
    if (isEmpty(p)) {
        return 0;
    }
    
    else {
        return 1 + NbElmt(p->next);
    }
}

infotype Min(address p) {
    if (isEmpty(p)) {
        return 0;
    }
    
    infotype min = p->info;
    address temp = p->next;
    
    while (temp != NULL) {
        if (temp->info < min) {
            min = temp->info;
        }
        temp = temp->next;
    }
    
    return min;
}

infotype Rerata(address p) {
    if (isEmpty(p)) {
        return 0;
    }
    
    int sum = 0;
    int count = 0;
    address temp = p;
    
    while (temp != NULL) {
        sum += temp->info;
        count++;
        temp = temp->next;
    }
    
    return sum / count;
}

address BalikList(address p) {
    address prev = NULL;
    address current = p;
    address next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}