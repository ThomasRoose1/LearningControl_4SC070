clear; clc; close all;


% INPUT FILES (SCHAALBAAR)
files = {
    'First_trail_basisfunc_na0_nb3.mat'
    'Second_trail_withbasisfunc_nb4_na0.mat'
};

labels = {
    'nb3'
    'nb4'
};

nData = numel(files);


% LOAD DATA
DATA = cell(nData,1);

for i = 1:nData %[output:group:847596d1]
    tmp = load(files{i}); %[output:08042373]
    DATA{i} = tmp.history;
end %[output:group:847596d1]



% CONFIG
idx_x   = 2;
idx_phi = 3;

colors = lines(nData);
%[text] 
%[text] Detectie valid last trail data
lastValid = zeros(nData,1);

for i = 1:nData
    
    H = DATA{i};
    Ntr = size(H.e,1);
    
    lastK = 0;
    
    for k = 1:Ntr
        
        ok = true;
        
        % eNorm check
        if k > size(H.eNorm,1) || ~any(isfinite(H.eNorm(k,:)))
            ok = false;
        end
        
        % f check
        if ok
            f = H.f(k,:,:);
            if ~any(isfinite(f(:)))
                ok = false;
            end
        end
        
        % fupdate check
        if ok
            fu = H.fupdate(k,:,:);
            if ~any(isfinite(fu(:)))
                ok = false;
            end
        end
        
        % e check
        if ok
            e = H.e(k,:,:);
            if ~any(isfinite(e(:)))
                ok = false;
            end
        end
        
        if ok
            lastK = k;
        end
        
    end
    
    lastValid(i) = lastK;
end

lastTrial = min(lastValid);

fprintf('Correct detected last valid trial = %d\n', lastTrial);
%[text] 
%[text] Figure
figure('Position',[50 80 1800 850])


% LOOP OVER KANALEN (x + phi)
for ch = 1:2

    if ch == 1
        idx = idx_x;
        name = 'x';
    else
        idx = idx_phi;
        name = '\phi';
    end

  
    % 1. REFERENCE
    subplot(2,4,(ch-1)*4 + 1)
    hold on; grid on;

    for i = 1:nData
        r = squeeze(DATA{i}.r(1,:,idx));
        plot(r,'Color',colors(i,:),'LineWidth',1.2);
    end

    title(['Reference r - ' name])
    legend(labels)


    % 2. FEEDFORWARD + UPDATE
    subplot(2,4,(ch-1)*4 + 2)
    hold on; grid on;

    for i = 1:nData

        f  = squeeze(DATA{i}.f(lastTrial,:,idx));
        fu = squeeze(DATA{i}.fupdate(lastTrial,:,idx));

        plot(f,'Color',colors(i,:))
        plot(f + fu,'--','Color',colors(i,:),'LineWidth',1.2)

    end

    title(['f + fupdate - ' name])


    % 3. ERROR
    subplot(2,4,(ch-1)*4 + 3)
    hold on; grid on;

    for i = 1:nData
        e = squeeze(DATA{i}.e(lastTrial,:,idx));
        plot(e,'Color',colors(i,:))
    end

    title(['Error e - ' name])


    % 4. eNORM
    subplot(2,4,(ch-1)*4 + 4)
    hold on; grid on;

    for i = 1:nData
        plot(DATA{i}.eNorm(1:lastTrial,idx), ...
            'Color',colors(i,:), ...
            'LineWidth',1.2);
    end

    xline(lastTrial,'k:','LineWidth',2)

    title(['eNorm - ' name])
    xlabel('Trial')
end

sgtitle(sprintf('ILC comparison (robust last trial = %d)', lastTrial))
%%
%[text] Save figure
%% Save figure in dated folder

% Timestamp voor bestandsnaam
timestamp = datestr(now,'yyyymmdd_HHMMSS');

% Datum-map (bijv. 2026-06-22)
dateFolder = datestr(now,'yyyy-mm-dd');

% Maak map als die nog niet bestaat
if ~exist(dateFolder,'dir')
    mkdir(dateFolder);
end

% Bestandsnaam
outName = sprintf('ILC_comparison_lastTrial_%d_%s.png', lastTrial, timestamp);

% Volledig pad
fullPath = fullfile(dateFolder, outName);

% Opslaan
exportgraphics(gcf, fullPath, 'Resolution', 300);

fprintf('Figure saved as: %s\n', fullPath);

%[appendix]{"version":"1.0"}
%---
%[metadata:view]
%   data: {"layout":"onright","rightPanelPercent":22.2}
%---
%[output:08042373]
%   data: {"dataType":"error","outputData":{"errorType":"runtime","text":"Error using <a href=\"matlab:matlab.lang.internal.introspective.errorDocCallback('load')\" style=\"font-weight:bold\">load<\/a>\nFirst_trail_basisfunc_na0_nb3.mat is not found in the current folder or on the MATLAB path, but exists in:\n    C:\\git\\LearningControl_4SC070\\Challenge\\experiment\\Results\\12_6\n\n<a href = \"matlab:internal.matlab.desktop.commandwindow.executeCommandForUser('cd ''C:\\git\\LearningControl_4SC070\\Challenge\\experiment\\Results\\12_6''')\">Change the MATLAB current folder<\/a> or <a href = \"matlab:internal.matlab.desktop.commandwindow.executeCommandForUser('addpath ''C:\\git\\LearningControl_4SC070\\Challenge\\experiment\\Results\\12_6''')\">add its folder to the MATLAB path<\/a>."}}
%---
