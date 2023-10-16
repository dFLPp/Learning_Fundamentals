// fazendo um servidor DNS com hashmaps

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class DNSServer {
    private Map<String, DNSRecord> dnsMap;

    public DNSServer() {
        dnsMap = new HashMap<>();
    }

    public void addRecord(DNSRecord record) {
        dnsMap.put(record.getIpAddress(), record);
    }

    public DNSRecord getRecord(String ipAddress) {
        return dnsMap.get(ipAddress);
    }

    public void printAllRecords() {
        for (DNSRecord record : dnsMap.values()) {
            System.out.println(record);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DNSServer dnsServer = new DNSServer();

        while (true) {
            System.out.println("1 - Add DNS Record");
            System.out.println("2 - Get URL for IP Address");
            System.out.println("3 - Print All DNS Records");
            System.out.println("4 - Exit");
            System.out.print("Select an option: ");

            int option = scanner.nextInt();
            scanner.nextLine();

            switch (option) {
                case 1:
                    System.out.print("Enter IP Address: ");
                    String ipAddress = scanner.nextLine();
                    System.out.print("Enter URL: ");
                    String url = scanner.nextLine();
                    DNSRecord record = new DNSRecord(ipAddress, url);
                    dnsServer.addRecord(record);
                    break;
                case 2:
                    System.out.print("Enter IP Address: ");
                    String searchIpAddress = scanner.nextLine();
                    DNSRecord result = dnsServer.getRecord(searchIpAddress);
                    if (result != null) {
                        System.out.println("Record: " + result);
                    } else {
                        System.out.println("Record not found.");
                    }
                    break;
                case 3:
                    dnsServer.printAllRecords();
                    break;
                case 4:
                    System.out.println("Exiting...");
                    scanner.close();
                    System.exit(0);
                default:
                    System.out.println("Invalid option.");
            }
        }
    }
}

class DNSRecord {
    private String ipAddress;
    private String url;

    public DNSRecord(String ipAddress, String url) {
        this.ipAddress = ipAddress;
        this.url = url;
    }

    public String getIpAddress() {
        return ipAddress;
    }

    public String getUrl() {
        return url;
    }

    @Override
    public String toString() {
        return "IP Address: " + ipAddress + ", URL: " + url;
    }
}
