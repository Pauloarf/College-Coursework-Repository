import csv
import json
import argparse

def csv_to_json(csv_file_path, json_file_path):
    data = []
    with open(csv_file_path, mode='r', encoding='utf-8') as csv_file:
        csv_reader = csv.DictReader(csv_file, delimiter=';', quotechar='"')
        for row in csv_reader:
            try:
                row['precoContratual'] = float(row['precoContratual'].replace(',', '.')) if row['precoContratual'] else None
            except (ValueError, AttributeError):
                pass
                
            try:
                row['prazoExecucao'] = int(row['prazoExecucao']) if row['prazoExecucao'] else None
            except (ValueError, AttributeError):
                pass
                
            data.append(row)
    
    with open(json_file_path, mode='w', encoding='utf-8') as json_file:
        json.dump(data, json_file, indent=4, ensure_ascii=False)
    
    print(f"Successfully converted {csv_file_path} to {json_file_path}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Convert semicolon-delimited CSV to JSON')
    parser.add_argument('input_csv', help='Path to the input CSV file')
    parser.add_argument('output_json', help='Path to the output JSON file')
    
    args = parser.parse_args()
    
    csv_to_json(args.input_csv, args.output_json)