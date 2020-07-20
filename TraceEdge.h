#define TraceEdge( x, y ){\
	Vector Start = SDK::Interfaces::g_pPlayerMove->origin;\
	Vector AirTemp = SDK::Interfaces::g_pPlayerMove->origin;\
	AirTemp[2] = -4096.0f;\
	pmtrace_t *pTrace = SDK::Interfaces::g_pEngine->PM_TraceLine ( Start, AirTemp, 1, ( SDK::Interfaces::g_pPlayerMove->flags & FL_DUCKING ) ? 1 : 0, -1 );\
	vec3_t vDis = ( AirTemp - SDK::Interfaces::g_pPlayerMove->origin ) * pTrace->fraction;\
	Start[2] -= 0.1f;\
	Start[2] -= -vDis[2];\
	Vector End = Start;\
	End[1] +=x * mind;\
	End[0] +=y * mind;\
	pmtrace_s* pTrace_s = SDK::Interfaces::g_pEngine->PM_TraceLine ( End, Start, 1, ( SDK::Interfaces::g_pPlayerMove->flags & FL_DUCKING ) ? 1 : 0, -1 );\
	if( !( pTrace_s->startsolid ) ) mind = ( pTrace_s->endpos - Start ).LengthXY ( ); }
