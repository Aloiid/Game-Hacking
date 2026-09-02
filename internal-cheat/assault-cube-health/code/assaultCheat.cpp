#include "includes.h"

int main() {

	DWORD pID = 0; 
	DWORD baseModule = 0; 
	DWORD LocalPlayerPtr = 0; //pointeur sur l'adresse du local player (donc la structure du personnage)
	HANDLE hProcess = INVALID_HANDLE_VALUE; 
	DWORD health = 4646; 
	//on récupère le pid de notre processus cible 
	pID = GetProcessID(L"ac_client.exe");
	
	baseModule = GetModuleBaseAddress(pID, L"ac_client.exe");

	printf("Valeur du PID : %d\n", pID); 
	printf("addresse de base du module : %p\n", &baseModule); 


	//maintenant on va ouvrir le processus cible 
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, pID); 

	//on va lire la mémoire avec ReadProcessMemory
	ReadProcessMemory(hProcess, (LPCVOID)(baseModule + 0x17E254), &LocalPlayerPtr, sizeof(LocalPlayerPtr), nullptr); 
	printf("valeur de l'adresse de la structure du local player %X\n", LocalPlayerPtr);


	//maintenant on entre dans une boucle pour écrire dans la mémoire tant que le jeu tourne 
	while (true) {
		WriteProcessMemory(hProcess, (LPVOID)(LocalPlayerPtr + 0xEC), &health, sizeof(health), nullptr); 
	}

	return 0; 
}