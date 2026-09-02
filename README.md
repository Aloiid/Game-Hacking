# game-hacking-notes

Notes personnelles sur le reverse engineering de jeux et la manipulation mémoire. Tout est fait sur des jeux open-source (AssaultCube) dans un cadre d'apprentissage.

## Contenu

- **AssaultCube / Health Pointer** — trouver une adresse statique avec Cheat Engine, pointer scan, puis lire/écrire en mémoire avec `ReadProcessMemory` / `WriteProcessMemory`

## Outils utilisés

- Cheat Engine — scan mémoire, dissect structures, pointer map
- Visual Studio — compilation C++
- WinAPI — `OpenProcess`, `ReadProcessMemory`, `WriteProcessMemory`, `CreateToolhelp32Snapshot`

## Objectif

Comprendre comment les valeurs sont stockées en mémoire, comment les retrouver via des pointeurs statiques, et comment interagir avec un process externe depuis du code C++. Base utile pour le reverse engineering et le développement bas niveau.
