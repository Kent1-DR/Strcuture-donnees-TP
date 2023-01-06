struct TableH {
    struct cle * cle;
    struct val * val;
    typeElement tab;
};

int htcrer()
{
    int tab[20];
}

int htput(cle,val,tab) {
    
}

cle = "nils"
val = "bonjour";

int hashage (char* val){
    int H = 0;
    int i = 0;
    
    while (val[i] != 0)
    H = H*31 + val[i++];

    return (H%20);
}






