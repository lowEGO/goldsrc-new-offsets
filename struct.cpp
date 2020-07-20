// valido apenas para o primario (pointer.cpp)
// publico
void DebugName(char *str)
			{
				if (strstr(str, "  ") != NULL)
				{
					strcpy(strstr(str, "  "), strstr(str, "  ") + 1);
					return;
				}
				if (str[0] == str[strlen(str) - 1])
				{
					char buf[256];
					char sbuf[2] = "A";
					sbuf[0] = str[0];
					strcpy_s(buf, sbuf);
					strcat_s(buf, str);
					strcpy(str, buf);
					return;
				}
				if (strlen(str) > 16)
				{
					str[strlen(str) - 1] = 0;
					return;
				}
				if (strstr(str, ".") != NULL)
				{
					*strstr(str, ".") = ',';
					return;
				}
				if (strstr(str, ",") != NULL)
				{
					*strstr(str, ",") = '.';
					return;
				}
				if (strstr(str, " ") != NULL)
				{
					char buf[256];
					strcpy_s(buf, str);
					strcpy(strstr(buf, " ") + 1, strstr(str, " "));
					strcpy(str, buf);
					return;
				}
				if (strstr(str, "-") != NULL)
				{
					*strstr(str, "-") = '=';
					return;
				}
				if (strstr(str, "=") != NULL)
				{
					*strstr(str, "=") = '-';
					return;
				}
				if (strstr(str, ":") != NULL)
				{
					*strstr(str, ":") = ';';
					return;
				}
				if (str[strlen(str) - 1] == str[strlen(str) - 2])
				{
					str[strlen(str) - 1] = 0;
					return;
				}
				strcat(str, ".");
			}
