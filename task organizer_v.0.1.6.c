#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>


int point, keluar,balik, a=1;

struct history{
	char RH[20];
	char time[50];
struct history *nextp;};
typedef struct history hist;
typedef hist *histp;

void push( histp *topP, char info[20] );
int isKosong( histp topP );
void printStack( histp skrgP );
histp stackP = NULL;

struct qhistory{
	char QH[20];
	char qtime[50];
	char sukses[8];
struct qhistory *qnextp;};
typedef struct qhistory qhist;
typedef qhist *qhistp;
qhist*qhisthead=NULL, *qhisttail=NULL;

void qpush( qhistp *qtopP, char qinfo[20] );
int qisKosong( qhistp qtopP );
void qprintStack( qhistp qskrgP );
qhistp qstackP = NULL;
	
struct task{
char namatask[20];
char desctask[100];
int pointtask;
int bulan,tanggal,jam,menit;
struct task *next;

};
typedef struct task task;
	task*taskhead=NULL, *tasktail=NULL;
struct reward{
char namareward[20];
char descreward[100];
int pointreward;
struct reward *next;

};
typedef struct reward reward;
	reward*rewardhead=NULL, *rewardtail=NULL;
	
	
struct tm *Sys_T;
getTime(){
    time_t current_time;
    char* c_time_string;
	
	
    /* Obtain current time. */
    current_time = time(NULL);
	Sys_T = localtime(&current_time); /*memasukan current_time ke struct tm*/
	
    if (current_time == ((time_t)-1))
    {
        (void) fprintf(stderr, "Failure to obtain the current time.\n");
        exit(EXIT_FAILURE);
    }


    /* Convert to local time format. */
    c_time_string = ctime(&current_time);

    if (c_time_string == NULL)
    {
        (void) fprintf(stderr, "Failure to convert the current time.\n");
        exit(EXIT_FAILURE);
    }

}

void qpush1(qhistp *qtopP, char qinfo[20]){
	qhistp qnewP;
	qnewP = malloc(sizeof(qhist));
	
	if(qnewP!= NULL){		
		strcpy( qnewP->QH, qinfo);
		strcpy(qnewP->qtime,asctime (Sys_T));
		strcpy(qnewP->sukses,"(sukses)");
		qnewP->qnextp = *qtopP;
		*qtopP = qnewP;
		
		
	}else{
	printf("%s tidak dimasukkan. Tidak ada memory tersedia.\n\n", qinfo[20]);
	}

}

void qpush0(qhistp *qtopP, char qinfo[20]){
	qhistp qnewP;
	qnewP = malloc(sizeof(qhist));
	
	if(qnewP!= NULL){

		strcpy( qnewP->QH, qinfo);
		strcpy(qnewP->qtime,asctime (Sys_T));
		strcpy(qnewP->sukses,"\t(gagal)");
		qnewP->qnextp = *qtopP;
		*qtopP = qnewP;
	
	}else{
	printf("%s tidak dimasukkan. Tidak ada memory tersedia.\n\n", qinfo[20]);
	}
}

int main(){
	system("color 37");
//	int i;
//	char datatask[20];
    FILE *in;
	in = fopen("point.txt", "r");
    fscanf(in,"%d",&point);
//    
//    FILE *loadtask = fopen("task.txt", "r");
// 	task *load = taskhead;
// 	for(i=0;i<1;i++){
//		fscanf(loadtask,"%s",datatask);		
//		fscanf(loadtask,"%d",load->pointtask);
//		fscanf(loadtask,"%d",load->bulan);
//		fscanf(loadtask,"%d",load->tanggal);
//		fscanf(loadtask,"%d",load->jam);
//		fscanf(loadtask,"%d",load->menit);
//		 load = load->next;
//	}
//	strcpy( load->namatask, datatask);
	menu();
return 0;
}

int menu(){
	
		FILE *out=fopen("point.txt","w");
	fprintf(out,"%d",point);
 	
 		FILE *savetask=fopen("task.txt","w");
	task *save = taskhead;
		while(save!=NULL){
		fprintf(savetask,"%s\n",save->namatask);
		fprintf(savetask,"%d\n",save->pointtask);
		fprintf(savetask,"%d\n",save->bulan);
		fprintf(savetask,"%d\n",save->tanggal);
		fprintf(savetask,"%d\n",save->jam);
		fprintf(savetask,"%d\n",save->menit);
		 save = save->next;
	}
	
		FILE *savetaskhis=fopen("task_history.txt","w");
	qhist *save2 = qhisthead;
		while(save2!=NULL){
		fprintf(savetaskhis,"%s\n",save2->QH);
		fprintf(savetaskhis,"%d\n",save2->qtime);
		fprintf(savetaskhis,"%d\n",save2->sukses);
		 save2 = save2->qnextp;
	}
	
 fclose(out);
 fclose(savetask);
 fclose(savetaskhis);
 system("cls");
	printf("SELF-CHECKED TASK ORGANIZER\n");
	printf("waktu sekarang: %s\n",getTime());
	printf("point sekarang: %d\n\n",point);

// printf("Day of Month = %d", Sys_T->tm_mday);
//    printf("\nMonth        = %d", Sys_T->tm_mon+1); /* Ditambah 1 karena Januari dimulai dari 0 */
//    printf("\nYear         = %d", 1900+Sys_T->tm_year); /* Ditambah 1900, karena tahun dimulai dari 1900 */
// 
//    printf("\n\nHour         = %d", Sys_T->tm_hour);
//    printf("\nMinutes      = %d", Sys_T->tm_min);
//    printf("\nSeconds      = %d", Sys_T->tm_sec);
// 
//    printf("\n\nDay of Week  = %d", Sys_T->tm_wday); /* 0-6 melambangkan Minggu-Sabtu */
//    printf("\nDay of Year  = %d\n", Sys_T->tm_yday);
 

//	printf("User: %s\n",datamenu->username);
//	printf("Point sekarang: %d\n",datamenu->pointuser);
	


	printf("Menu: \n");
	printf("[1]Menu task\n");
	printf("[2]Menu Reward\n");
	printf("[3]exit\n");
//	printf("[4]exit\n");


	switch (getch()){
		case '1':
			system("cls");
			showtask();
			break;	
		case '2':
			system("cls");
			menureward();
			break;	
		case'3':
		keluar=1;
		exit(0);
			break;	
//		case'4':
//			return 0;
//			break;
//		default:
////			printf("\n input invalid \ n");
//			system("cls");
//			menu();
//			break;
	}
//return 0;

}



showtask(){
	task *showtask;
	showtask = taskhead;
	printf("\nDAFTAR task: \n");
	while(showtask != NULL){
		printf(" [%s] point : %d \n\n",showtask->namatask,showtask->pointtask);
		printf("deadline: bulan %d, tanggal %d, jam %d menit %d\n",showtask->bulan,showtask->tanggal,showtask->jam,showtask->menit);
		showtask = showtask->next;
	}
	printf("\n");
	menutask();
}

menutask(){
		printf("Pilihan:\n");
	printf("[1]Tambah task\n");
	printf("[2]Hapus task\n");
	printf("[3]Finish task\n");
	printf("[4]Show completed task\n");
	printf("[5]Kembali ke menu\n");
	
	switch (getch()){
		case '1':
			addtask();
			break;
		case '2':
			deletetask();
			break;
		case'3':
			finishtask();
			break;
		case'4':
			qprintStack(qstackP);
			break;			
		case '5':		
			menu();
			break;
	}

system("cls");
showtask();
}

menureward(){
		reward *showData;
	showData = rewardhead;
	printf("\nDAFTAR REWARD: \n");
	while(showData != NULL){
		printf("%s : point %d \n",showData->namareward,showData->pointreward);
//		printf("%s \n",showData->descreward);
		showData = showData->next;
	}
	printf("\n");
	printf("Pilihan:\n");
	printf("[1]Tambah Reward\n");
	printf("[2]Claim reward\n");
	printf("[3]Hapus Reward\n");
	printf("[4]Show reward history\n");
	printf("[5]Kembali ke menu\n");
	
	
	switch (getch()){
		case '1':
			addreward();
			break;
		case '2':
			claimreward();
			break;
		case '3':
			deletereward();
			break;
		case '4':
			printStack(stackP);
			break;
		case '5':
			menu();
			break;
	}
	
}

addtask(){
	printf("TAMBAH task\n");
	char datanama[20];
	char datadesc[100];
	int datapoint;
	int databulan,datatanggal,datajam,datamenit;
	printf("\nMasukan nama task:");
	scanf("%s",&datanama);
//	printf("\nMasukan deskripsi task:");
//	gets(datadesc);
	printf("\nMasukan point dari task:");
	scanf("%d",&datapoint);
	printf("masukan tanggal deadline (dalam integer)\n");
	printf("bulan: ");
	scanf("%d",&databulan);
	printf("tanggal: ");
	scanf("%d",&datatanggal);
	printf("jam: ");
	scanf("%d",&datajam);
	printf("menit: ");
	scanf("%d",&datamenit);
	

//	printf("\nMasukan exp task:");
//	scanf("%d",&dataexp);
	
	task *barutask;
	barutask=(task*)malloc(sizeof(task));
	strcpy(barutask->namatask, datanama);
	barutask->pointtask = datapoint;
	barutask->bulan = databulan;
	barutask->tanggal = datatanggal;
	barutask->jam = datajam;
	barutask->menit = datamenit;
	strcpy( barutask->desctask, datadesc);
	
//	barutask->exptask = dataexp;
	barutask->next = NULL;
	
	if (taskhead == NULL){
		taskhead = barutask;
		tasktail = barutask;
	}
	else{
		tasktail->next = barutask;
		tasktail=barutask;
	}
	printf("\n");
}

addreward(){
		printf("TAMBAH REWARD \n");
	char datanama[20];
	char datadesc[100];
	int datapoint;
	
	printf("\nMasukan nama reward:");
	scanf("%s",&datanama);
//	printf("\nMasukan deskripsi reward:");
//	scanf("%s",&datadesc);
	printf("\nMasukan point untuk claim reward:");
	scanf("%d",&datapoint);
	
	reward *baru;
	baru=(reward*)malloc(sizeof(reward));
	strcpy( baru->namareward, datanama);
	strcpy( baru->descreward, datadesc);
	baru->pointreward = datapoint;

	baru->next = NULL;
	
	if (rewardhead == NULL){
		rewardhead = baru;
		rewardtail = baru;
	}
	else{
		rewardtail->next = baru;
		rewardtail=baru;
	}
	printf("\n");
	
}

deletetask(){
	char datanama[20];
	int compare;
	int hasil = 0;
	printf("Masukan nama task:");
	gets(datanama);
	
	task *hapus = taskhead, *previous=NULL;
	
	
	while(hapus!=NULL){
		compare = strcmp(hapus->namatask,datanama);
		if(compare==0){
			if(previous==NULL){
			taskhead = hapus->next;
			}
			else{
			previous->next=hapus->next;
			}
		printf("task %s telah dihapus dari daftar\n",datanama);
		hasil = 1;
		free(hapus);
		break;
		}
	previous = hapus;
	hapus = hapus->next;
}
}

deletereward(){
	char datanama[20];
	int compare;
	int hasil = 0;
	printf("Masukan nama reward:");
	scanf("%s",&datanama);
	
	reward *hapus = rewardhead, *previous=NULL;
	
	
	while(hapus!=NULL){
		compare = strcmp(hapus->namareward,datanama);
		if(compare==0){
			if(previous==NULL){
			rewardhead = hapus->next;
			}
			else{
			previous->next=hapus->next;
			}
		printf("reward %s telah dihapus dari daftar\n",datanama);
		hasil = 1;
		free(hapus);
		break;
		}
	previous = hapus;
	hapus = hapus->next;
}
}

finishtask(){
	char datanama[20];
	int compare,deadline;
	int hasil = 0;
	printf("Masukan nama task:");
	gets(datanama);
	
	task *finish = taskhead, *previous=NULL;
	
	
	while(finish!=NULL){
		compare = strcmp(finish->namatask,datanama);
		if(compare==0){
			if(previous==NULL){
			taskhead = finish->next;
			}
			else{
			previous->next=finish->next;
			}
		deadline = cekdeadline(finish->bulan,finish->tanggal,finish->jam,finish->menit);
		if(deadline==1){
		printf("task %s telah selesai dan anda mendapatkan point %d!!!\n",datanama,finish->pointtask);
		point = point + finish->pointtask;
			qpush1(&qstackP, datanama);
		}
		else{
			printf("Task %s sudah meleawati deadline. Anda tidak mendapatkan point... \n ",datanama);
			qpush0(&qstackP, datanama);
		}
		hasil = 1;
		free(finish);
		system("pause");
		break;
		}
		else{
			
		}
	previous = finish;
	finish = finish->next;
}
}

int cekdeadline(int bulan, int tanggal, int jam, int menit){
	int deadline;
	getTime();
	if(Sys_T->tm_mon+1 > bulan){
		deadline = 0;}
	else if(Sys_T->tm_mday > tanggal){
			deadline = 0;}
			else if(!Sys_T->tm_hour > jam){
				deadline = 0;}
				else if(Sys_T->tm_min > menit){
					deadline = 0;}
				else{
					deadline = 1;
				}
			
	return deadline;
}

claimreward(){
	char datanama[20];
	int compare;
	int hasil = 0;
	printf("Masukan nama reward yang akan di claim:");
	scanf("%s",&datanama);
	
	reward *claim = rewardhead, *previous=NULL;
	
	
	while(claim!=NULL){
		compare = strcmp(claim->namareward,datanama);
		if(compare==0){
			if(previous==NULL){
			rewardhead = claim->next;
			}
			else{
			previous->next=claim->next;
			}
			point = point - claim->pointreward;
		printf("reward %s telah di claim dan point anda sekarang %d\n",datanama,point);
		push(&stackP, datanama);
//		exp = exp + finish->exptask;
		hasil = 1;
		free(claim);
		break;
		}
	previous = claim;
	claim = claim->next;

}
	system("cls");
}

void push(histp *topP, char info[20]){
	histp newP;
	newP = malloc(sizeof(hist));
	
	if(newP!= NULL){
		strcpy( newP->RH, info);
		strcpy( newP->time, asctime (Sys_T));
		newP->nextp = *topP;
		*topP = newP;
	}else{
		printf("%s tidak dimasukkan. Tidak ada memory tersedia.\n\n", info[20]);
	}

}

void printStack(histp skrgP){
	if(skrgP == NULL) {
      printf( "Reward history kosong.\n\n");	
}else {
	printf("History reward : \n\n");
	while(skrgP!=NULL){
		printf("\t%d.",a);
		         printf( "%s\n", skrgP->RH );
		         printf( "%s\n", skrgP->time);
		         skrgP = skrgP->nextp;
		a++;
	}
	a=1;
}
system("pause");
system("cls");
}
int isKosong( histp topP ){
	return topP == NULL;
	
}



void qprintStack(qhistp qskrgP){
	if(qskrgP == NULL) {
      printf( "task history kosong.\n\n");	
}else {
	printf("History task : \n\n");
	while(qskrgP!=NULL){
		         printf( "\t%d. %s\n",a, qskrgP->QH );
		         printf( "\tSelesai pada :%s \t(%s)\n",qskrgP->qtime,qskrgP->sukses);
		         qskrgP = qskrgP->qnextp;
		a++;
	}
}
system("pause");
}
int qisKosong( qhistp qtopP ){
	return qtopP == NULL;
	
}
