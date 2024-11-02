find . -path "./minilibx" -prune -o \( -name "*.c" -o -name "*.h" \) -print | xargs norminette
