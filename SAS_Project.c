// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

struct reservation
{
  int reference;
  char nom[25];
  char prenom[25];
  char telephone[25];
  int age;  
  char statut[25];
  char date[25];
};

int count = 0;
int referenceCount = 0;

struct reservation res[100];

void AddReservation()
{
  printf("======= Ajouter une reservation ======= \n");
  res[count].reference = referenceCount;
  printf("Entrez nom : ");
  scanf("%s", &res[count].nom);
  printf("Entrez prenom : ");
  scanf("%s", &res[count].prenom);
  printf("Entrez telephone : ");
  scanf("%s", &res[count].telephone);
  printf("Entrez age : ");
  scanf("%d", &res[count].age);
  printf("Entrez statut (valide, reporte, annule, traite) : ");
  scanf("%s", &res[count].statut);
  printf("Entrez la date : ");
  scanf("%s", &res[count].date);

  referenceCount++;
  count++;
  printf("============================== \n");
}

void AfficherTout()
{
  printf("========================== La liste des reservation =============================================== \n");
  for (int i = 0; i < count; i++)
  {
    printf(" res_%d : ", i + 1);
    printf(" Reference : %d |", res[i].reference);
    printf(" Nom : %s |", res[i].nom);
    printf(" Prenom : %s |", res[i].prenom);
    printf(" Telephone : %s |", res[i].telephone);
    printf(" Age : %d |", res[i].age);
    printf(" Status : %s |", res[i].statut);
    printf(" La date : %s .\n", res[i].date);
  }
  printf("====================================================================================================================== \n");
};

int Search_reference(int reference)
{
  for (int i = 0; i < count; i++)
  {
    if (reference == res[i].reference)
    {
      return i;
    }
  }
  return -1;
};


void AfficheReserve(int index)
{
  printf("================================> La reservations releve <========================= \n");
    printf(" Reference : %d |", res[index].reference);
    printf(" Nom : %s |", res[index].nom);
    printf(" Prenom : %s |", res[index].prenom);
    printf(" Telephone : %s |", res[index].telephone);
    printf(" Age : %d |", res[index].age);
    printf(" Status : %s |", res[index].statut);
    printf(" La date : %s \n", res[index].date);
  printf("========================================================================== \n");
};

void ModifierReservation()
{
  int searchReference,  newAge;
  char newNom[25], newPrenom[25], newDate[25], newTelephone[25], newStatut[25];
  int m;
  printf("Entrez reference de reservation pour modifier : ");
  scanf("%d", &searchReference);

  int index = Search_reference(searchReference);

  if (index != -1)
  {
    AfficheReserve(index);

    printf("========== \n");
    printf("-1- Modifier le nom \n");
    printf("-2- Modifier Prenom \n");
    printf("-3- Modifier telephone \n");
    printf("-4- Modifier age \n");
    printf("-5- Modifier statut \n");
    printf("-6- Modifier la date \n");
    printf("========== \n");

    printf(" Entrez le chempe que tu veux modifier : ");
    scanf("%d", &m);

    switch (m)
    {
    case 1:
      printf("modifier le nom : ");
      scanf("%s", &newNom);

      

      if (strlen(newNom) > 0)
      {
        strcpy(res[index].nom, newNom);
      }
      break;
    case 2:
      printf("modifier Prenom : ");
      scanf("%s", &newPrenom);
      
      if (strlen(newPrenom) > 0)
      {
        strcpy(res[index].prenom, newPrenom);
      }
      break;
    case 3:
      printf("Modifier telephone : ");
      scanf("%s", newTelephone);

      if (strlen(newTelephone) > 0)
      {
        strcpy(res[index].telephone, newTelephone);
      }
      break;
    case 4:
      printf("modifier age : ");
      scanf("%d", &newAge);
      
      res[index].age = newAge ;

      break;

    case 5:
      printf("Modifier statut : ");
      scanf("%s", &newStatut);

      if (strlen(newStatut) > 0)
      {
        strcpy(res[index].statut, newStatut);
      }
      break;

       case 6:
      printf("Modifier la date : ");
      scanf("%s", &newDate);

      if (strlen(newDate) > 0)
      {
        strcpy(res[index].date, newDate);
      }
      break;

    default:
      break;
    }
  }
  else
  {
    printf("==> Désoler la reservation non releve !!! <== \n");
  }
};

void SupprimerReserve()
{
  printf("======= Supprimer un reservation ======= \n");
  int searchReference;
  int removeClick;
  printf("Recherche la reservation que vous souhaitez supprimez : ");
  scanf("%d", &searchReference);

  int index = Search_reference(searchReference);

  if (index != -1)
  {
    AfficheReserve(index);

    printf(" Alors spprimez ici en cliquant sur : -1- : ");

    scanf("%d", &removeClick);

    if (removeClick == 1)
    {
      for (int j = index; j <= count - 1; j++)
      {
        res[j] = res[j + 1];
      }
      count--;
      printf("Le reservation est supprimez \n");
    }
  }
  else
  {
    printf("==> Désoler la reservation non releve !!! <==");
  }

  printf("============================== \n");
}


void statistiques() {
    int age_total = 0;
    int count_0_18 = 0, count_19_35 = 0, count_36_plus = 0;

    for (int i = 0; i < count; i++) {
        age_total += res[i].age;
        if (res[i].age <= 18) {
            count_0_18++;
        }
        else if (res[i].age <= 35){
            count_19_35++;
        } else {
            count_36_plus++;
        }
    }

    double moyenne_age ;
    
     if (count > 0) {
           moyenne_age =  (age_total / count) ;
     }
    else {
         moyenne_age =  0.0 ;
    }

    printf("Moyenne d\'age: %.2f\n", moyenne_age);
    printf("0-18 ans: %d\n", count_0_18);
    printf("19-35 ans: %d\n", count_19_35);
    printf("36+ ans: %d\n", count_36_plus);
}



int rechercheParNom(char nom[100]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(res[i].nom, nom) == 0) {  
            return i; 
        }
    }
    return -1;  
}


void recherche() {
    int choix,index;
    printf("\n--- Recherche ---\n");
    printf("1. Recherche par reference\n");
    printf("2. Recherche par nom\n");

    printf("Entrez votre choix: ");
    scanf("%d", &choix);

    switch (choix) {
        case 1: {
            int ref;
            printf("Entrez la reference de la reservation a rechercher: ");
            scanf("%d", &ref);
            index = Search_reference(ref);

            if (index != -1) {
                AfficheReserve(index);
            } else {
                printf("Aucune reservation trouvee pour la reference \n");
            }
            break;
        }
        case 2: {
            char nom[100];

            printf("Entrez le nom a rechercher: ");
            scanf("%s",&nom);

            index = rechercheParNom(nom);

            if (index != -1) {
                AfficheReserve(index);
            } else {
                printf("aucune reservation trouve pour le nom ");
            }
            break;
        }
        default:
            break;
    }
}


int main()
{

  int choix;

  do
  {
    printf("***************************************** \n");
    printf("-1- Ajouter une reservation \n");
    printf("-2- Modifier une reservation \n");
    printf("-3- Supprimer une reservation \n");
    printf("-4- Afficher les details d\'une reservation \n");
    printf("-5- Tri des reservations \n");
    printf("-6- Statistiques \n");
    printf("-7- Recherche des reservations \n");
    printf("*********************************************** \n");

    printf("======> choisissez un servise : ");
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
      AddReservation();  
      break;
    case 2:
      ModifierReservation();
      break;
    case 3: 
      SupprimerReserve();
      break;
    case 4:
      AfficherTout();
      break;
      
    case 6:
      statistiques();
      break;
    case 7 :
      recherche();
    break;
    default:
      printf("Entrez le nombre entre 1 et 8");
      break;
    }

  } while (choix != 0);

  return 0;
}


