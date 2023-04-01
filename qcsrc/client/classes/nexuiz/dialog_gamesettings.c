#ifdef INTERFACE
CLASS(NexuizGameSettingsDialog) EXTENDS(NexuizRootDialog)
	METHOD(NexuizGameSettingsDialog, fill, void(entity)) // to be overridden by user to fill the dialog with controls
	METHOD(NexuizGameSettingsDialog, configureDialog, void(entity))
	ATTRIB(NexuizGameSettingsDialog, title, string, "Game Settings")
	ATTRIB(NexuizGameSettingsDialog, color, vector, SKINCOLOR_DIALOG_TEAMSELECT)
	ATTRIB(NexuizGameSettingsDialog, intendedWidth, float, 0.5)
	ATTRIB(NexuizGameSettingsDialog, rows, float, 26)
	ATTRIB(NexuizGameSettingsDialog, columns, float, 6)
	ATTRIB(NexuizGameSettingsDialog, name, string, "GameSettings")
ENDCLASS(NexuizGameSettingsDialog)
#endif

#ifdef IMPLEMENTATION
void configureDialogNexuizGameSettingsDialog(entity me) {
	if not(extension_DP_CSQC_QUERYRENDERENTITY)
		me.rows = me.rows + 2;

	configureDialogNexuizDialog(me); //Parent method
}

void(entity me, entity bnt) showHudDialogGameSettingsDialog {
	GUI_Show(GUI_HUD);
}

void(entity me) loadCvarsNexuizGameSettingsDialogGunAlpha {
	float f = (cvar("r_drawviewmodel") ? cvar("cl_gunalpha") : -1);
	me.value = ((f == 0) ? 1 : (f < 0 ? 0 : f));
}

void(entity me) saveCvarsNexuizGameSettingsDialogGunAlpha {
	if (me.value == 0)
		cvar_set("cl_gunalpha", "-1");
	else {
		cvar_set("r_drawviewmodel", "1");
		cvar_set("cl_gunalpha", ftos(me.value));
	}
}

void fillNexuizGameSettingsDialog(entity me)
{
	entity e;
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 2.5, e = makeNexuizTextLabel(0, "Show names:"));
		if not(extension_DP_CSQC_QUERYRENDERENTITY)
			e.disabled = 1;
		me.TD(me, 1, 2.5, e = makeNexuizTextSlider("cl_shownames"));
			e.addValue(e, "Never", "0");
			e.addValue(e, "Only for teammates", "1");
			e.addValue(e, "Always", "2");
			e.configureNexuizTextSliderValues(e);
		if not(extension_DP_CSQC_QUERYRENDERENTITY) {
			e.disabled = 1;
			me.TDempty(me, 0.5);
			me.TD(me, 1, 0.25, e = makeNexuizTextLabel(0, "*"));
			e.colorL = SKINCOLOR_TEXT_WARNING;
		}
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 2.5, e = makeNexuizTextLabel(0, "Show names view sector:"));
		if not(extension_DP_CSQC_QUERYRENDERENTITY)
			e.disabled = 1;
		me.TD(me, 1, 2.5, e = makeNexuizTextSlider("cl_shownames_cos"));
			e.addValue(e, "Wide", "0");
			e.addValue(e, "Narrow", "0.9");
			e.addValue(e, "Very narrow", "0.99");
			e.configureNexuizTextSliderValues(e);
		if not(extension_DP_CSQC_QUERYRENDERENTITY) {
			e.disabled = 1;
			me.TDempty(me, 0.5);
			me.TD(me, 1, 0.25, e = makeNexuizTextLabel(0, "*"));
			e.colorL = SKINCOLOR_TEXT_WARNING;
		}
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 5, e = makeNexuizCheckBox(0, "cl_voice", "Player voices"));
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 2.5, e = makeNexuizTextLabel(0, "Weapon opacity:"));
		me.TD(me, 1, 2.5, e = makeNexuizSlider(0, 1, 0.05, "cl_gunalpha"));
		e.saveCvars = saveCvarsNexuizGameSettingsDialogGunAlpha;
		e.loadCvars = loadCvarsNexuizGameSettingsDialogGunAlpha;
		e.loadCvars(e); //cvar must be reloaded with custom loadCvars function
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 2.5, e = makeNexuizTextLabel(0, "Weapon position:"));
		me.TD(me, 1, 2.5, e = makeNexuizTextSlider("cl_gunalign"));
			e.addValue(e, "Right", "1");
			e.addValue(e, "Left", "2");
			e.addValue(e, "Center or Right", "3");
			e.addValue(e, "Center or Left", "4");
			e.configureNexuizTextSliderValues(e);
	me.TR(me);
		me.TDempty(me, 0.5);
		me.TD(me, 1, 5, e = makeNexuizCheckBox(0, "cl_gunalign_force_center", "Force center position"));
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 5, e = makeNexuizCheckBox(0, "cl_nex_secondary_zoom_disable", "Disable nex zoom with secondary attack"));
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 5, e = makeNexuizCheckBox(0, "cl_showweaponspawns", "Weapon location hint"));
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 5, e = makeNexuizCheckBox(0, "cl_recoil", "Recoil from shots"));
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 5, e = makeNexuizCheckBox(0, "cl_damage_screen_effects", "Force screen effect on damage"));
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 2.5, e = makeNexuizTextLabel(0, "Damage indicator:"));
		me.TD(me, 1, 2.5, e = makeNexuizTextSlider("cl_damageindicator"));
			e.addValue(e, "Hidden", "0");
			e.addValue(e, "Fast", "0.5");
			e.addValue(e, "Normal", "1.5");
			e.addValue(e, "Slow", "2.5");
			e.configureNexuizTextSliderValues(e);
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 2.5, e = makeNexuizTextLabel(0, "Announcer print:"));
		me.TD(me, 1, 2.5, e = makeNexuizTextSlider("cl_announcer_print"));
			e.addValue(e, "Hidden", "0");
			e.addValue(e, "Fast", "1");
			e.addValue(e, "Normal", "2");
			e.addValue(e, "Slow", "2");
			e.configureNexuizTextSliderValues(e);
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 2.5, e = makeNexuizTextLabel(0, "Weapon bar fade time:"));
		me.TD(me, 1, 2.5, e = makeNexuizTextSlider("sbar_weapons_fadetime"));
			e.addValue(e, "Always hidden", "0");
			e.addValue(e, "Short", "1");
			e.addValue(e, "Normal", "2");
			e.addValue(e, "Long", "3");
			e.configureNexuizTextSliderValues(e);
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 5, e = makeNexuizCheckBox(0, "sbar_weapons_show_ammo", "Show ammo in weapon bar"));
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 5, e = makeNexuizCheckBox(0, "sbar_weapons_order", "Reverse weapon order"));
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 2.5, e = makeNexuizTextLabel(0, "Weapon bar fade speed:"));
		me.TD(me, 1, 2.5, e = makeNexuizTextSlider("sbar_weapons_fadespeed"));
			e.addValue(e, "Fast", "4");
			e.addValue(e, "Normal", "2");
			e.addValue(e, "Slow", "1");
			e.addValue(e, "Stopped", "0");
			e.configureNexuizTextSliderValues(e);
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 5, e = makeNexuizCheckBox(0, "cl_autoswitch", "Auto switch weapons on pickup"));
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, (g_velocity_rounding ? 2.5 : 5), e = makeNexuizCheckBox(0, "cl_cts_strafe_helper", "Show strafe helper in CTS"));
		if (g_velocity_rounding)
			me.TD(me, 1, 2.5, e = makeNexuizCheckBox(0, "cl_cts_snap_helper", "and snap zones"));
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 5, e = makeNexuizCheckBox(0, "cl_cts_position_helper", "Show position helper in CTS"));
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 2.5, e = makeNexuizCheckBox(0, "cl_showacceleration", "Show acceleration"));
		me.TD(me, 1, 2.5, e = makeNexuizCheckBox(0, "cl_cts_showacceleration", "Auto enable in CTS"));
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 2.5, e = makeNexuizCheckBox(0, "cl_showspeed", "Show speed"));
		me.TD(me, 1, 2.5, e = makeNexuizCheckBox(0, "cl_cts_showspeed", "Auto enable in CTS"));
	if not(extension_DP_CSQC_QUERYRENDERENTITY) {
		me.TR(me);
			me.TDempty(me, 0.25);
			me.TD(me, 1, 4, e = makeNexuizTextLabel(0, "(*) Some features are unavailable. Your client is outdated."));
			e.colorL = SKINCOLOR_TEXT_WARNING;
		me.TR(me);
			me.TDempty(me, 0.25);
			me.TD(me, 1, 3, e = makeNexuizTextLabel(0, "Download Rexuiz client here:"));
			e.colorL = SKINCOLOR_TEXT_WARNING;
			me.TD(me, 1, 1, e = makeNexuizTextLabel(0, "http://rexuiz.com"));
			e.colorL = SKINCOLOR_TEXT_LINK;
	}
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 5, e = makeNexuizCheckBox(0, "sbar_increment_maptime", "Incremental timer"));
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 5, e = makeNexuizCheckBox(0, "sbar_showcurrentammo", "Show only current ammo"));
	me.TR(me);
		me.TDempty(me, 0.25);
		me.TD(me, 1, 5, e = makeNexuizButton("HUD Selection...", '0 0 0'));
			e.onClick = showHudDialogGameSettingsDialog;
	me.TR(me);
	me.TR(me);
		me.TD(me, 1, me.columns, makeNexuizCommandButton("Apply immediately", '0 0 0', ";sendcvar cl_voice;sendcvar cl_gunalpha;sendcvar cl_autoswitch;sendcvar cl_gunalign_force_center;sendcvar cl_gunalign;sendcvar cl_showweaponspawns;sendcvar cl_damage_screen_effects", COMMANDBUTTON_CLOSE));
}
#endif
