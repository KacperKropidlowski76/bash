#!/bin/bash

# Sprawdzenie, czy podano argument (folder do przeszukania)
if [ $# -ne 1 ]; then
    echo "Użycie: $0 <folder>"
    exit 1
fi

# Pobranie nazwy użytkownika i daty
USER_NAME=$(whoami)
CURRENT_DATE=$(date +"%Y-%m-%d")

# Definiowanie nazwy archiwum
ARCHIVE_NAME="${USER_NAME}_backup_${CURRENT_DATE}.tar.gz"

# Katalog docelowy
BACKUP_DIR="$HOME/backups"

# Tworzenie katalogu backupów, jeśli nie istnieje
mkdir -p "$BACKUP_DIR"

# Wyszukiwanie plików .txt i dodanie ich do archiwum
find "$1" -type f -name "*.txt" | tar -czf "$BACKUP_DIR/$ARCHIVE_NAME" -T -

# Sprawdzenie, czy archiwum zostało utworzone
if [ -f "$BACKUP_DIR/$ARCHIVE_NAME" ]; then
    echo "Backup zapisany w: $BACKUP_DIR/$ARCHIVE_NAME"
else
    echo "Błąd podczas tworzenia archiwum."
    exit 1
fi
