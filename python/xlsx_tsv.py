import xlrd
import csv

# open the tsv file(output) in unicode format
with open('AY.tsv', 'w', encoding='utf-8') as TSVfile:
    wr = csv.writer(TSVfile, delimiter="\t")

    # open the xlsx file
    xlfile = xlrd.open_workbook('AY.xlsx')
    # retrieve sheet
    sheet = xlfile.sheet_by_index(0)

    # write rows into TSVfile
    line_lists = []
    for row in range(sheet.nrows):
        line_list = sheet.row_values(row)
        #print(line_list)
        if len(line_list):
            line_lists.append(line_list)
    wr.writerows(line_lists)
