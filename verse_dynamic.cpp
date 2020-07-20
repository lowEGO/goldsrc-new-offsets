void Box(float x, float y, float w, float h, ImU32 team)
{
	if (!cvar.visual_box) return;
	ImGui::GetCurrentWindow()->DrawList->AddRect({ x, y }, { x + w, y + h }, team);
}
 
bool bCalcScreen(cl_entity_s* ent, int& x, int& y, int& w, int& h)
{
	if (!g_Player[ent->index].bGotHitboxPlayer) return false;
	Vector vOrigin;
	if (!WorldToScreen(ent->origin, vOrigin)) return false;
	int x0 = vOrigin.x, x1 = vOrigin.x, y0 = vOrigin.y, y1 = vOrigin.y;
	int iMaxHitboxes = g_Player[ent->index].iMaxHitboxes;
	if (iMaxHitboxes == 21) iMaxHitboxes = 20;
	for (unsigned int hitbox = 0; hitbox < iMaxHitboxes; hitbox++)
	{
		for (unsigned int point = 0; point < 8; point++)
		{
			Vector vHitbox;
			if (!WorldToScreen(g_PlayerExtraInfoList[ent->index].vHitboxMulti[hitbox][point], vHitbox)) return false;
			x0 = min(x0, vHitbox.x);
			x1 = max(x1, vHitbox.x);
			y0 = min(y0, vHitbox.y);
			y1 = max(y1, vHitbox.y);
		}
	}
	x = int(round(x0));
	y = int(round(y0));
	w = int(round(x1 - x0));
	h = int(round(y1 - y0));
	return true;
}
 
void DrawPlayerEsp()
{
	for (unsigned int id = 1; id <= g_Engine.GetMaxClients(); id++)
	{
		cl_entity_s* ent = g_Engine.GetEntityByIndex(id);
		int x, y, w, h;
		if (bCalcScreen(ent, x, y, w, h))
		{
			Box(x, y, w, h, Team(id));
		}
	}
}
