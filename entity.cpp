			void Main::AddEntity ( const char *Name, const Vector &vOrigin, const int &Type )
			{
				if ( EntityIndex < MAX_ENTITY )
				{
					lstrcpy ( Entity[EntityIndex].Name, Name );

					Entity[EntityIndex].vOrigin = vOrigin;
					Entity[EntityIndex].Type = Type;

					++EntityIndex;
				}
				else
					ClearEntity ( );
			}

			void Main::ClearEntity ( )
			{
				for ( int Index = 0; Index < EntityIndex; ++Index )
				{
					memset ( &Entity[Index].Name, 64, 0 );

					Entity[Index].vOrigin = Vector ( 0.0f );
					Entity[Index].Type = 0;
				}

				EntityIndex = 0;
			}
