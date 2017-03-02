var
    subCntPause, subNumPause, appRule, rules, rulesDef, input,
    manPause = false;
interval = {
    set: false,
    id: 0
};

function adoptSubCnt() {
    for (var i = 0; !document.frm.fPauseNumSel[i].checked; i++);
    document.frm[document.frm.fPauseNumSel[i].value + 'Ba'].value = document.frm.fSubCnt.value;
}

function switchRules(target) {
    document.frm.fRules.value =
        ((target != 'inf') == document.frm.fRules.readOnly) ? (document.frm.fRules.readOnly = target == 'inf') ? (
            rulesDef = document.frm.fRules.value, document.frm.fRules.tmp = '',
            initRules() ? eval(
                'for (var i = 0; i < rules.length; i++)' +
                '  document.frm.fRules.tmp += \'[\' + (i + 1) + \'] \' + rules[i][0] + \'->\' + (rules[i].term ? \'.\' : \'\') + rules[i][1] + String.fromCharCode(10)'
            ) : 0,
            document.frm.fRules.tmp
        ) : rulesDef : document.frm.fRules.value;
}

function retIntLeast(mInt, least) {
    mInt = parseInt(mInt);
    return Math.max(isNaN(mInt) ? least : mInt, least);
}

function selSubNumPause() {
    for (var i = 0; !(document.frm.fPauseNumSel[i].checked); i++);
    try {
        var tmp = eval(document.frm[document.frm.fPauseNumSel[i].value + 'Ba'].value + document.frm[document.frm.fPauseNumSel[i].value + 'Ff'].value);
    } catch (exception) {
        return 1;
    }
    return typeof tmp == 'undefined' ? 1 : Math.max(Math.round(tmp), 1);
}

function genDebugStr() {
    var
        debugStr = '',
        debugSubStr = new Array(document.frm.fSubCnt.value, subCntPause + '', input.length + '', (appRule + 1) + ''),
        debugInd = new Array('TSteps', 'CSteps', 'InpSize', 'RuleNum'),
        lead = document.frm.fLeadingNum.value.split(',');
    for (var i = 0; i < debugInd.length; i++)
        if (document.frm['fPrn' + debugInd[i]].checked) {
            lead[i] = typeof lead[i] == 'undefined' ? 0 : retIntLeast(lead[i], 0);
            while (debugSubStr[i].length <= lead[i]) debugSubStr[i] = '0'.concat(debugSubStr[i]);
            debugStr += debugSubStr[i] + '|';
        }
    return debugStr.length ? '[' + debugStr.substring(0, debugStr.length - 1) + '] ' : '';
}

function startInt() {
    with(interval) if (set) set = (window.clearInterval(id), false);
    document.frm.fStatus.value = 'initializing...';
    document.frm.fSubCnt.value = 0;
    document.frm.fOutput.value = '';
    input = document.frm.fInput.value;
    initRules() ? contInt() : (document.frm.fStatus.value = 'no rules defined', 0);
}

function initRules() {
    rules = (document.frm.fRules.readOnly ? rulesDef : document.frm.fRules.value).concat('\n').match(/.*->.*\r*\n/g);
    if (!rules) return false;
    for (var i = 0; i < rules.length; i++) {
        rules[i] = rules[i].replace(/\r*\n/, '').split('->');
        if (rules[i].term = rules[i][1].charAt(0) == '.')
            rules[i][1] = rules[i][1].substring(1, rules[i][1].length);
    }
    return true;
}

function contInt() {
    document.frm.fStatus.value = 'processing...';
    document.frm.fPause.disabled = !(document.frm.fCont.disabled = true);
    subCntPause = appRule = 0;
    if (document.frm.fPauseNum.checked) subNumPause = selSubNumPause();
    with(interval) id = (set = true, window.setInterval('subLoop()', 1));
}

function prSubLoopEsc(status) {
    document.frm.fStatus.value = status;
    document.frm.fPause.disabled = true;
    document.frm.fCont.disabled = status.substring(0, 4) == 'done';
    with(interval) set = (window.clearInterval(id), false);
}

function subLoop() {
    if (manPause) {
        manPause = false;
        prSubLoopEsc('paused / manually');
        return;
    }
    if (appRule == rules.length) {
        prSubLoopEsc('done / no match');
        return;
    }
    if (input.indexOf(rules[appRule][0]) == -1)
        appRule++;
    else {
        input = input.replace(rules[appRule][0], rules[appRule][1]);
        document.frm.fSubCnt.value++;
        subCntPause++;
        document.frm.fOutput.value += genDebugStr() + input + '\n';
        if (rules[appRule].term) {
            prSubLoopEsc('done / terminated');
            return;
        }
        appRule = 0;
        if (document.frm.fPauseNum.checked && subCntPause == subNumPause) {
            prSubLoopEsc('paused / auto 1');
            return;
        }
        if (document.frm.fPauseSize.checked && eval(input.length + document.frm.fPauseSizeOpr.options[document.frm.fPauseSizeOpr.options.selectedIndex].value + retIntLeast(document.frm.fPauseSizeVal.value, 1))) {
            prSubLoopEsc('paused / auto 2');
            return;
        }
        if (document.frm.fPauseLook.checked && input == document.frm.fPauseLookVal.value) {
            prSubLoopEsc('paused / auto 3');
        }
    }
}
