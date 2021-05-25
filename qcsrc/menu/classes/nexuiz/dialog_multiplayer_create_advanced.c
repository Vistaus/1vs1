#ifdef INTERFACE
CLASS(NexuizAdvancedDialog) EXTENDS(NexuizDialog)
	METHOD(NexuizAdvancedDialog, fill, void(entity))
	METHOD(NexuizAdvancedDialog, showNotify, void(entity))
	METHOD(NexuizAdvancedDialog, close, void(entity))
	ATTRIB(NexuizAdvancedDialog, title, string, _("Advanced server settings"))
	ATTRIB(NexuizAdvancedDialog, color, vector, SKINCOLOR_DIALOG_ADVANCED)
	ATTRIB(NexuizAdvancedDialog, intendedWidth, float, 0.5)
	ATTRIB(NexuizAdvancedDialog, rows, float, 14)
	ATTRIB(NexuizAdvancedDialog, columns, float, 3)
	ATTRIB(NexuizAdvancedDialog, refilterEntity, entity, NULL)
ENDCLASS(NexuizAdvancedDialog)
#endif

#ifdef IMPLEMENTATION
void(entity me) showNotifyNexuizAdvancedDialog {
	gui_load_all_cvars(me);
}

void(entity me) fillNexuizAdvancedDialog {
	entity e;
	me.TR(me);
		me.TD(me, 1, 1.2, makeNexuizTextLabel(0, _("Game settings:")));
	me.TR(me);
		me.TDempty(me, 0.2);
		me.TD(me, 1, 1.2, e = makeNexuizCheckBox(0, "sv_spectate", _("Allow spectating")));
	me.TR(me);
		me.TDempty(me, 0.2);
		me.TD(me, 1, 1.2, e = makeNexuizTextLabel(0, _("Spawn shield:")));
		me.TD(me, 1, 1.7, e = makeNexuizSlider(0, 15, 0.5, "g_spawnshieldtime"));
	me.TR(me);
		me.TDempty(me, 0.2);
		me.TD(me, 1, 1.2, e = makeNexuizTextLabel(0, _("Start delay:")));
		me.TD(me, 1, 1.7, e = makeNexuizSlider(0, 30, 0.5, "g_start_delay"));
	me.TR(me);
	me.TR(me);
		me.TDempty(me, 0.2);
		me.TD(me, 1, 1.2, e = makeNexuizCheckBoxEx(2, 0, "g_antilag", _("AntiLag")));
	me.TR(me);
	me.TR(me);
		me.TD(me, 1, 1.2, makeNexuizTextLabel(0, _("Teamplay settings:")));
	me.TR(me);
		me.TDempty(me, 0.2);
		me.TD(me, 1, 1.2, e = makeNexuizTextLabel(0, _("Friendly fire scale:")));
		me.TD(me, 1, 1.7, e = makeNexuizSlider(0, 1.0, 0.05, "g_friendlyfire"));
	me.TR(me);
		me.TDempty(me, 0.2);
		me.TD(me, 1, 1.2, e = makeNexuizTextLabel(0, _("Friendly fire penalty:")));
		me.TD(me, 1, 1.7, e = makeNexuizSlider(0, 1.0, 0.05, "g_mirrordamage"));
	me.TR(me);
		me.TDempty(me, 0.2);
		me.TD(me, 1, 1.2, e = makeNexuizTextLabel(0, _("Teams:")));
		me.TD(me, 1, 1.7, e = makeNexuizTextSlider("g_tdm_teams_override"));
			e.addValue(e, _("Default"), "0");
			e.addValue(e, _("2 teams"), "2");
			e.addValue(e, _("3 teams"), "3");
			e.addValue(e, _("4 teams"), "4");
			e.configureNexuizTextSliderValues(e);
		gui_make_multi(e, "g_domination_teams_override g_keyhunt_teams_override");
	me.gotoRC(me, me.rows - 1, 0);
		me.TD(me, 1, me.columns, e = makeNexuizButton(_("OK"), '0 0 0'));
			e.onClick = Dialog_Close;
			e.onClickEntity = me;
}

void(entity me) closeNexuizAdvancedDialog {
	if(me.refilterEntity)
		me.refilterEntity.refilter(me.refilterEntity);

	closeDialog(me);
}
#endif
