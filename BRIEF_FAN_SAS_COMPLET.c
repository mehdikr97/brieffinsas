#include <stdio.h>
#include <string.h>

typedef struct {
    int jour;
    int mois;
    int annee;
} Newdate;

typedef struct {
    char titre[30];
    char description[30];
    int priorite; // 1 for High, 2 for Low
    Newdate date;
} tache;

tache tch[10];
int nm = 0;

// Function to display all tasks
void affichage() {
    if (nm == 0) {
        printf("Aucune tache a afficher.\n");
        return;
    }
    for (int i = 0; i < nm; i++) {
        printf("Tache %d\n", i + 1);
        printf("Titre: %s\n", tch[i].titre);
        printf("Description: %s\n", tch[i].description);
        printf("Date: %d/%d/%d\n", tch[i].date.jour, tch[i].date.mois, tch[i].date.annee);
        if (tch[i].priorite == 1) {
            printf("Priorité: High\n");
        } else if (tch[i].priorite == 2) {
            printf("Priorité: Low\n");
        } else {
            printf("Priorité: Inconnue\n");
        }
        printf("----------------------------\n");
    }
}

// Function to filter tasks by priority
void filtrerParPriorite(int prioriteRecherchee) {
    int trouve = 0;//utilisée pour suivre si des tâches avec la priorité spécifiée ont été trouvées.
     
    
    printf("Tâches avec priorité ");

    if (prioriteRecherchee == 1) {
        printf("High:\n");
    } else if (prioriteRecherchee == 2) {
        printf("Low:\n");
    } else {
        printf("inconnue.\n");
        return;
    }
    for (int i = 0; i < nm; i++) {
        if (tch[i].priorite == prioriteRecherchee) {
            printf("Tâche %d\n", i + 1);
            printf("Titre: %s\n", tch[i].titre);
            printf("Description: %s\n", tch[i].description);
            printf("Date: %d/%d/%d\n", tch[i].date.jour, tch[i].date.mois, tch[i].date.annee);
            printf("----------------------------\n");
            trouve = 1;//au moins une tâche avec la priorité spécifiée a été trouvée.
        }
    }
    {  if (!trouve)//vérifie TROUVE toujours à 0
        printf("Aucune tâche trouvée avec la priorité spécifiée.\n");
    
    }
 
}

// Function to modify a task
void modifier(tache tch[], int index) {
    if (index >= 0 && index < nm) {
        printf("Mise à jour des informations de la tâche %d\n", index + 1);

        printf("Nouveau titre: ");
        scanf("%s", tch[index].titre);
        printf("Nouvelle description: ");
        scanf("%s", tch[index].description);
        printf("Nouvelle priorité (1 pour High, 2 pour Low): ");
        scanf("%d", &tch[index].priorite);
        printf("Nouvelle date (jour mois année): ");
        scanf("%d %d %d", &tch[index].date.jour, &tch[index].date.mois, &tch[index].date.annee);
        printf("Informations mises à jour avec succès.\n");
    } else {
        printf("Index invalide.\n");
    }
}

// Function to validate date
int dateValide(int jour, int mois, int annee) {
    if (annee < 2024|| annee > 2100) {
        return 0;// retourne la date est invalide.
    }
    if (mois < 1 || mois > 12) {
        return 0;
    }
    if (jour < 1 || jour > 31) {
        return 0;
    }
    return 1; // retourne la date valide 
}

// Function to add a task
void ajouter() {
 
int prioriteValide;
    printf("Entrez les données de la tâche:\n");
    printf("Titre: ");
    scanf("%s", tch[nm].titre);
    printf("Description: ");
    scanf("%s", tch[nm].description);

    do {
        printf("Date (jour mois année): ");
        scanf("%d %d %d", &tch[nm].date.jour, &tch[nm].date.mois, &tch[nm].date.annee);
        if (!dateValide(tch[nm].date.jour, tch[nm].date.mois, tch[nm].date.annee)) {
            printf("Date invalide. Réessayez.\n");
        }
    } while (!dateValide(tch[nm].date.jour, tch[nm].date.mois, tch[nm].date.annee));
    do {
        int prioriteValide=0;
    printf("Priorité (1 pour High, 2 pour Low): ");
    scanf("%d", &tch[nm].priorite);
        if (tch[nm].priorite == 1 || tch[nm].priorite == 2)
        { prioriteValide = 1; } 
        else { printf("Priorité invalide. Réessayez.\n");
    }}while(!prioriteValide);
        
    

    nm++;
}

// Function to delete a task
void supprimer(int index) {
    if (index < 0 || index >= nm) {
        printf("Index invalide. Impossible de supprimer.\n");
    } else {
        for (int i = index; i <=nm; i++) {
            tch[i] = tch[i + 1];
        }
        nm--;
        printf("Tâche supprimée avec succès.\n");
    }
}

int main() {
    int choix;
    int index;
    int priorite;

    do {
                printf("-------------------Menu---------------------------\n");
printf("--");
        printf("\t1 - Ajouter une tâche : \t\t--\n");
        printf("--");

        printf("\t2 - Afficher les tâches :\t\t--\n");
        printf("--");

        printf("\t3 - Supprimer une tâche :\t\t--\n");
        printf("--");

        printf("\t4 - Modifier une tâche :\t\t--\n");
        printf("--");

        printf("\t5 - Filtrer les tâches par priorité \t--\n");
        printf("--");

        printf("\t0 - Quitter \t\t\t\t--\n");
        printf("--");


        printf("\tEntrez votre choix: ");

        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter();
                break;
            case 2:
                affichage();
                break;
            case 3:
                printf("Entrez l'index de la tâche à supprimer: ");
                scanf("%d", &index);
                supprimer(index );
                break;
            case 4:
                printf("Entrez l'index de la tâche à modifier: ");
                scanf("%d", &index);
                modifier(tch, index );
                break;
            case 5:
                printf("Entrez la priorité à filtrer (1: High, 2: Low): ");
                scanf("%d", &priorite);
                filtrerParPriorite(priorite);
                break;
            case 0:
                printf("Programme terminé.\n");
                break;
            default:
                printf("Choix invalide. Réessayez.\n");
                break;
        }
    } while (choix != 6);

    return 0;
}