			void FindPoint(float *point, int screenwidth, int screenheight, int degrees)
			{
				float x2 = screenwidth / 2;
				float y2 = screenheight / 2;

				float d = sqrt(pow((point[0] - x2), 2) + (pow((point[1] - y2), 2))); //distancia entre elementos
				float r = degrees / d; //ratio

				point[0] = r * point[0] + (1 - r) * x2; //achar a divisao do segmento
				point[1] = r * point[1] + (1 - r) * y2; //ratio?? (1-r):r
			}

			bool WorldToScreen(float *vOrigin, float *vScreen, bool &behind)
			{
				qboolean st = SDK::Interfaces::g_Engine.pTriAPI->WorldToScreen(vOrigin, vScreen);

				if (st)
					behind = true;
				else
					behind = false;

				float x = SDK::Interfaces::g_Screen.iWidth / 2 + 0.5 * vScreen[0] * SDK::Interfaces::g_Screen.iWidth + 0.5;
				float y = SDK::Interfaces::g_Screen.iHeight / 2 - 0.5 * vScreen[1] * SDK::Interfaces::g_Screen.iHeight + 0.5;

				vScreen[0] = x;
				vScreen[1] = y;

				if (vScreen[0] > SDK::Interfaces::g_Screen.iHeight || vScreen[0] < 0 || vScreen[1] > SDK::Interfaces::g_Screen.iWidth || vScreen[1] < 0 || st)
				{
					FindPoint(vScreen, SDK::Interfaces::g_Screen.iWidth, SDK::Interfaces::g_Screen.iHeight, SDK::Interfaces::g_Screen.iHeight / 2);

					return false;
				}

				return true;
			}
